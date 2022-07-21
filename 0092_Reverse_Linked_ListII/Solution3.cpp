#include <Solution.h>
#include <iostream>

// 1 2 3 4 5 6 7 8   3  7
ListNode* Solution::reverseBetween3(ListNode* head, int left, int right) {
	if (left == right || !head) return head;

	ListNode* dummy = new ListNode();
	dummy->next = head;

	ListNode* iter = dummy;
	ListNode* prev = nullptr;
	for (int i = 0 ; i < left ; ++i) {
		prev = iter;
		iter = iter->next;
	}

	ListNode* rPrev = nullptr;
	ListNode* rNext = nullptr;
	for (int i = left ; i <= right ; ++i) {
		rNext = iter->next;
		iter->next = rPrev;
		rPrev = iter;
		iter = rNext;
	}

	prev->next->next = iter;
	prev->next = rPrev;
	return dummy->next;
}
