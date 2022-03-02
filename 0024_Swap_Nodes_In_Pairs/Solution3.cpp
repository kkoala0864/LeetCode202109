#include <Solution.h>
#include <iostream>

ListNode* Solution::swapPairs3(ListNode* head) {
	if (!head || !head->next) return head;

	ListNode* iter = head;
	ListNode* prev = nullptr;

	while (iter && iter->next) {
		ListNode* tmp = iter->next;
		iter->next = tmp->next;
		tmp->next = iter;
		if (prev) {
			prev->next = tmp;
		} else {
			head = tmp;
		}
		prev = iter;
		iter = iter->next;
	}

	return head;
}
