#include <Solution.h>
#include <iostream>

ListNode* Solution::partition(ListNode* head, int x) {
	if (!head) return nullptr;
	ListNode* iter = head;
	ListNode* smaller = nullptr;
	ListNode* smallIter = nullptr;
	ListNode* bigger = nullptr;
	ListNode* bigIter = nullptr;
	while (iter) {
		if (iter->val < x) {
			if (!smaller) {
				smaller = iter;
				smallIter = smaller;
			} else {
				smallIter->next = iter;
				smallIter = smallIter->next;
			}
		} else {
			if (!bigger) {
				bigger = iter;
				bigIter = bigger;
			} else {
				bigIter->next = iter;
				bigIter = bigIter->next;
			}
		}
		iter = iter->next;
	}
	if (bigIter) bigIter->next = nullptr;
	if (smaller) smallIter->next = bigger;
	else smaller = bigger;

	return smaller;
}
