#include <Solution.h>
#include <iostream>

ListNode *Solution::rotateRight(ListNode *head, int k) {
	if (!head)
		return head;
	int size = 0;
	ListNode *iter = head;
	ListNode *tail = nullptr;

	while (iter) {
		++size;
		tail = iter;
		iter = iter->next;
	}

	k %= size;
	if (k == 0 || size == 1)
		return head;
	k = (size - k);
	ListNode *result = head;
	while (k--) {
		iter = result;
		result = result->next;
	}
	iter->next = nullptr;
	tail->next = head;
	return result;
}
