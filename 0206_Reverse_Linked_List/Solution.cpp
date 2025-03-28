#include <Solution.h>
#include <iostream>

ListNode *Solution::reverseList(ListNode *head) {
	if (!head)
		return head;

	ListNode *iter = head;
	ListNode *last = nullptr;
	ListNode *next = nullptr;

	while (iter) {
		next = iter->next;
		iter->next = last;
		last = iter;
		iter = next;
	}

	return last;
}
