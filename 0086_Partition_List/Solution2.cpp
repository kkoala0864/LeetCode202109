#include <Solution.h>
#include <iostream>

ListNode* Solution::partition2(ListNode* head, int x) {
	if (!head || !head->next) return head;
	ListNode* big = nullptr, *small = nullptr;
	ListNode* sIter = nullptr, *bIter = nullptr;

	while (head) {
		if (head->val < x) {
			if (small) {
				sIter->next = head;
				sIter = sIter->next;
			} else {
				small = sIter = head;
			}
		} else {
			if (big) {
				bIter->next = head;
				bIter = bIter->next;
			} else {
				big = bIter = head;
			}
		}
		head = head->next;
	}

	if (bIter) bIter->next = nullptr;
	if (sIter) sIter->next = big;
	return small ? small : big;
}
