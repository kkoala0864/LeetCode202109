#include <Solution.h>
#include <iostream>

bool Solution::isPalindrome(ListNode* head) {
	int n = 0;
	ListNode *iter = head;

	while (iter) {
		++n;
		iter = iter->next;
	}
	if (n == 1) return true;
	int half = n & 1 ? n / 2 + 1 : n / 2;

	ListNode* prev = nullptr, *cur = head, *next = head->next;

	while (half--) {
		cur->next = prev;
		prev = cur;
		cur = next;
		next = next->next;
	}

	if (n & 1) prev = prev->next;
	while (cur && prev) {
		if (cur->val != prev->val) return false;
		cur = cur->next;
		prev = prev->next;
	}
	return true;
}
