#include <Solution.h>
#include <iostream>

bool Solution::isPalindrome2(ListNode *head) {
	if (!head || !head->next)
		return true;
	int size = 0;
	ListNode *iter = head;
	while (iter) {
		++size;
		iter = iter->next;
	}

	int limit = size & 1 ? (size >> 1) + 1 : size >> 1;

	ListNode *prev = nullptr, *next = nullptr;
	iter = head;
	while (limit--) {
		next = iter->next;
		iter->next = prev;
		prev = iter;
		iter = next;
	}
	if (size & 1)
		prev = prev->next;
	while (prev && iter) {
		if (prev->val != iter->val)
			return false;
		prev = prev->next;
		iter = iter->next;
	}
	return true;
}
