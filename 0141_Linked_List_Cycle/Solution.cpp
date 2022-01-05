#include <Solution.h>
#include <iostream>
#include <climits>

bool Solution::hasCycle(ListNode *head) {
	ListNode* iter = head;
	while (iter) {
		if (iter->val == INT_MAX) return true;
		iter->val = INT_MAX;
		iter = iter->next;
	}
	return false;
}
