#include <Solution.h>
#include <iostream>

ListNode *Solution::reverseKGroup(ListNode *head, int k) {
	ListNode *iter = head, *prev = nullptr, *next = nullptr, *gtail = head, *ghead = nullptr;

	ListNode *dummy = new ListNode();
	dummy->next = head;
	ListNode *lastTail = dummy;
	int cnt = k;

	while (gtail) {
		gtail = gtail->next;
		--cnt;
		if (cnt == 0) {
			ghead = iter;
			cnt = k;

			while (iter != gtail) {
				next = iter->next;
				iter->next = prev;
				prev = iter;
				iter = next;
			}
			ghead->next = gtail;
			lastTail->next = prev;
			lastTail = ghead;
		}
	}
	return dummy->next;
}
