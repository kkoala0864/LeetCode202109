#include <Solution.h>
#include <iostream>

ListNode *Solution::detectCycle2(ListNode *head) {
	if (!head)
		return nullptr;
	ListNode *fast = head;
	ListNode *slow = head;

	do {
		fast = fast->next;
		if (fast)
			fast = fast->next;
		slow = slow->next;
	} while (fast && fast != slow);

	if (!fast)
		return nullptr;

	fast = head;
	while (fast != slow) {
		fast = fast->next;
		slow = slow->next;
	}
	return fast;
}
