#include <Solution.h>
#include <iostream>

vector<ListNode*> Solution::splitListToParts(ListNode* head, int k) {

	int cnt = 0;
	ListNode *iter = head;
	while (iter) {
		++cnt;
		iter = iter->next;
	}
	iter = head;
	int base = cnt / k;
	int mod = cnt % k;

	vector<ListNode*> result;
	ListNode* last = nullptr;
	while (iter) {
		result.emplace_back(iter);
		for (int i = 0 ; i < base ; ++i) {
			last = iter;
			iter = iter->next;
		}
		if (mod > 0) {
			last = iter;
			iter = iter->next;
			--mod;
		}
		last->next = nullptr;
	}
	while (result.size() < k) {
		result.emplace_back(nullptr);
	}
	return result;
}
