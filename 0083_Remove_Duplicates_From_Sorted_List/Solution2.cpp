#include <Solution.h>
#include <iostream>

ListNode *Solution::deleteDuplicates2(ListNode *head) {
	if (!head)
		return head;
	ListNode *iter = nullptr;
	ListNode *cur = head;

	while (cur) {
		iter = cur->next;
		while (iter && iter->val == cur->val) {
			iter = iter->next;
		}
		cur->next = iter;
		cur = cur->next;
	}
	return head;
}
