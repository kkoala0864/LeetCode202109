#include <Solution.h>
#include <iostream>

ListNode *removeElements2(ListNode *head, int val) {
	if (!head)
		return head;
	ListNode *result = nullptr;
	ListNode *iter = nullptr;
	while (head) {
		if (head->val != val) {
			if (result) {
				iter->next = head;
				iter = iter->next;
			} else {
				result = head;
				iter = head;
			}
		}
		head = head->next;
	}
	if (iter)
		iter->next = nullptr;
	return result;
}
