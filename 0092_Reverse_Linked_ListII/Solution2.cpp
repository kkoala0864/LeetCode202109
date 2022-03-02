#include <Solution.h>
#include <iostream>

ListNode* Solution::reverseBetween2(ListNode* head, int left, int right) {
	if (!head) return head;

	int cnt = 1;
	ListNode* dummy = new ListNode(0, head);
	ListNode* iter = head, *prev = dummy;

	while (iter) {
		if (cnt == left) {
			ListNode* leftNode = iter;
			ListNode* rp = prev;
			ListNode* next = iter->next;
			while (cnt <= right) {
				++cnt;
				next = iter->next;
				iter->next = rp;
				rp = iter;
				iter = next;
			}
			prev->next = rp;
			leftNode->next = iter;
		} else {
			++cnt;
		}
		prev = iter;
		if (iter) iter = iter->next;
	}
	return dummy->next;
}
