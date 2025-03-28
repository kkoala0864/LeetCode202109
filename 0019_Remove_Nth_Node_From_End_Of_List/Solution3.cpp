#include <Solution.h>
#include <iostream>
#include <vector>

using std::vector;

ListNode *Solution::removeNthFromEnd3(ListNode *head, int n) {
	ListNode *dummy = new ListNode(0, head);
	ListNode *first = dummy;
	ListNode *second = dummy;
	for (int i = 0; i < n; ++i) {
		first = first->next;
	}

	while (first->next) {
		second = second->next;
		first = first->next;
	}
	second->next = second->next->next;
	return dummy->next;
}
