#include <Solution.h>
#include <iostream>

ListNode* Solution::swapPairs3(ListNode* head) {
	ListNode* iter = head;
	ListNode* dummy = new ListNode();
	dummy->next = head;
	ListNode* prev = dummy;
	ListNode* next = nullptr;

	while (iter && iter->next) {
		next = iter->next->next;
		iter->next->next = iter;
		prev->next = iter->next;
		iter->next = next;
		prev = iter;
		iter = iter->next;
	}
	return dummy->next;
}
