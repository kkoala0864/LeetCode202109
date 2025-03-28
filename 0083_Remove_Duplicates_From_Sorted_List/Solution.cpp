#include <Solution.h>
#include <iostream>

ListNode *Solution::deleteDuplicates(ListNode *head) {
	if (!head || !head->next)
		return head;

	ListNode *iter = head->next;
	ListNode *node = head;
	while (iter) {
		if (node->val == iter->val) {
			iter = iter->next;
			continue;
		} else {
			node->next = iter;
			node = node->next;
			iter = iter->next;
		}
	}
	node->next = iter;
	return head;
}
