#include <Solution.h>
#include <iostream>

ListNode *Solution::reverseList2(ListNode *head) {
	if (!head)
		return head;
	ListNode *cur = head;
	ListNode *prev = nullptr;
	ListNode *next = nullptr;

	while (cur) {
		next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
	}
	return prev;
}
