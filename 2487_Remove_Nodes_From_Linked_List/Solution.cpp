#include <Solution.h>
#include <iostream>
#include <vector>

using std::vector;

ListNode *Solution::removeNodes(ListNode *head) {
	vector<ListNode *> l;

	ListNode *iter = head;
	while (iter) {
		while (!l.empty() && l.back()->val < iter->val) {
			l.pop_back();
		}
		l.emplace_back(iter);
		iter = iter->next;
	}
	for (int i = 0; i < l.size() - 1; ++i) {
		l[i]->next = l[i + 1];
	}
	l.back()->next = nullptr;
	return l[0];
}
