#include <Solution.h>
#include <iostream>

ListNode *removeElements(ListNode *head, int val) {
	ListNode *newhead = nullptr;
	ListNode *newIter = nullptr;
	ListNode *iter = head;
	while (iter) {
		if (iter->val != val) {
			if (!newhead) {
				newhead = iter;
				newIter = iter;
			} else {
				newIter->next = iter;
				newIter = newIter->next;
			}
		}
		iter = iter->next;
	}
	if (newIter)
		newIter->next = nullptr;
	return newhead;
}
