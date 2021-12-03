#include <Solution.h>
#include <iostream>

bool Solution::hasCycle2(ListNode *head) {
	if (!head || !head->next) return false;

	ListNode* slow = head;
	ListNode* fast = head->next;
	while (slow && fast && slow != fast) {
		slow = slow->next;
		fast = fast->next;
		if (fast) fast = fast->next;
	}
	return slow == fast;
}
