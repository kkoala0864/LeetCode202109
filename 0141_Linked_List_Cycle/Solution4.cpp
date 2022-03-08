#include <Solution.h>
#include <iostream>

bool Solution::hasCycle4(ListNode *head) {
	if (!head || !head->next) return false;

	ListNode* fast = head->next, *slow = head;
	while (fast && fast->next) {
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast) return true;
	}
	return false;
}
