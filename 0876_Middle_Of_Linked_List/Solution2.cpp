#include <Solution.h>
#include <iostream>

ListNode *Solution::middleNode2(ListNode *head) {
	ListNode *slow = head;
	ListNode *fast = head;
	while (fast && fast->next) {
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}
