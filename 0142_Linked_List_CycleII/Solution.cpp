#include <Solution.h>
#include <iostream>

ListNode* Solution::detectCycle(ListNode *head) {
	ListNode* slow = head;
	ListNode* fast = head;

	while (fast && fast->next) {
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast) break;
	}

	if (!fast || !fast->next) return nullptr;

	fast = head;
	while (fast != slow) {
		fast = fast->next;
		slow = slow->next;
	}
	return fast;
}
