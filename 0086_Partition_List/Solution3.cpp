#include <Solution.h>
#include <iostream>

ListNode* Solution::partition3(ListNode* head, int x) {
	ListNode* greater = nullptr;
	ListNode* ghead = nullptr;
	ListNode* less = nullptr;
	ListNode* lhead = nullptr;
	ListNode* iter = head;

	while (iter) {
		if (iter->val >= x) {
			if (!greater) {
				greater = iter;
				ghead = iter;
			} else {
				greater->next = iter;
				greater = greater->next;
			}
		} else {
			if (!less) {
				less = iter;
				lhead = iter;
			} else {
				less->next = iter;
				less = less->next;
			}
		}
		iter = iter->next;
	}
	if (ghead) greater->next = nullptr;
	if (lhead) less->next = ghead;
	return lhead ? lhead : ghead;
}
