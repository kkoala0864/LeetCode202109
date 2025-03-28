#include <Solution.h>
#include <iostream>

bool Solution::hasCycle3(ListNode *head) {
	if (!head || !head->next)
		return false;
	ListNode *slow = head;
	ListNode *fast = head->next;

	while (fast && fast != slow) {
		slow = slow->next;
		fast = fast->next;
		if (fast)
			fast = fast->next;
	}
	return fast == slow;
}
