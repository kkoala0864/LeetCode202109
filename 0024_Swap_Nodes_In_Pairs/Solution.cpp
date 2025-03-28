#include <Solution.h>
#include <iostream>

ListNode *Solution::swapPairs(ListNode *head) {
	if (!head)
		return head;
	ListNode *iter = head;
	ListNode *prev = new ListNode(0, head);
	ListNode *prevHead = prev;
	ListNode *next = nullptr;
	while (iter) {
		ListNode *first = iter;
		iter = iter->next;
		ListNode *second = iter;
		if (second) {
			iter = iter->next;
			second->next = first;
			first->next = iter;
			prev->next = second;
			prev = prev->next->next;
		}
	}
	return prevHead->next;
}
