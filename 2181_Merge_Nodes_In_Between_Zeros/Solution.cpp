#include <Solution.h>
#include <iostream>

ListNode *Solution::mergeNodes(ListNode *head) {
	ListNode *iter = head->next;
	ListNode *curZero = head;
	while (iter) {
		if (iter->val == 0) {
			curZero->next = iter->next ? iter : nullptr;
			curZero = curZero->next;
		} else {
			curZero->val += iter->val;
		}
		iter = iter->next;
	}
	return head;
}
