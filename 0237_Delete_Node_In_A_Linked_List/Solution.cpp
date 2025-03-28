#include <Solution.h>
#include <iostream>
using std::swap;

void Solution::deleteNode(ListNode *node) {
	ListNode *iter = node;

	while (iter->next->next) {
		swap(iter->val, iter->next->val);
	}

	swap(iter->val, iter->next->val);
	iter->next = nullptr;
}
