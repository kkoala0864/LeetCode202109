#include <Solution.h>
#include <iostream>

ListNode* Solution::swapPairs2(ListNode* head) {
	if (!head || !head->next) return head;

	ListNode* iter = head;
	ListNode* prev = new ListNode();
	head = head->next;

	while (iter && iter->next) {
		prev->next = iter->next;
		iter->next = iter->next->next;
		prev->next->next = iter;
		prev = iter;
		iter = iter->next;
	}
	return head;
}
