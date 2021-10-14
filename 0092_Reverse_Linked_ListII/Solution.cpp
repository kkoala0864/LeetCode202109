#include <Solution.h>
#include <iostream>

// [1]
// leftPin = nullptr
// leftStart = 1

// [1, 2, 3, 4, 5]   [2 - 4]
// leftPin = 1
// leftStart = 2
// [3, 5]
// leftPin = nullptr
// leftStart = 3
//
ListNode* Solution::reverseBetween(ListNode* head, int left, int right) {
	ListNode* iter = head;
	ListNode* leftPin = nullptr;
	ListNode* leftStart = nullptr;
	ListNode* prev = nullptr;
	ListNode* next = nullptr;
	int cnt = 0;

	while (iter) {
		++cnt;
		if (cnt == (left - 1)) leftPin = iter;

		if ((cnt >= left) && (cnt <= right)) {
			if (cnt == left) leftStart = iter;
			next = iter->next;
			iter->next = prev;
			prev = iter;
			iter = next;
			if (cnt == right) {
				if (leftPin) leftPin->next = prev;
				else head = prev;
				leftStart->next = iter;
			}
		} else {
			iter = iter->next;
		}
	}
	return head;
}
