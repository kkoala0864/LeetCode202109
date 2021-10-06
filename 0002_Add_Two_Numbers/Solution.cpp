#include <Solution.h>
#include <iostream>
#include <queue>

using std::queue;

ListNode* Solution::addTwoNumbers(ListNode* l1, ListNode* l2) {
	queue<int> l1V, l2V;
	ListNode* result;
	ListNode* iter;

	while (l1) {
		l1V.emplace(l1->val);
		l1 = l1->next;
	}
	while (l2) {
		l2V.emplace(l2->val);
		l2 = l2->next;
	}

	int carry = 0;
	while (!l1V.empty() || !l2V.empty()) {
		int l1val = l1V.empty() ? 0 : l1V.front();
		if (!l1V.empty()) l1V.pop();
		int l2val = l2V.empty() ? 0 : l2V.front();
		if (!l2V.empty()) l2V.pop();
		int val = l1val + l2val + carry;
		ListNode* node = new ListNode(val % 10);
		carry = val / 10;
		if (!iter) {
			result = node;
			iter = result;
		} else {
			iter->next = node;
			iter = iter->next;
		}
	}
	if (carry > 0) iter->next = new ListNode(carry);
	return result;
}
