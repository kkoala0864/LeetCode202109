#include <Solution.h>
#include <iostream>

// 1 2 3 4
//
// 1 2 3
// 1 2
// 1 2 3 4 5
ListNode *Solution::deleteMiddle(ListNode *head) {
	if (!head || !head->next)
		return nullptr;

	ListNode *slow = head;
	ListNode *fast = head->next;

	while (fast->next && fast->next->next) {
		slow = slow->next;
		fast = fast->next->next;
	}

	slow->next = slow->next->next;
	return head;
}
