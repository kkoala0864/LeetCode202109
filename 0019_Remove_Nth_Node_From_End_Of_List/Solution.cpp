#include <Solution.h>
#include <iostream>
#include <vector>

using std::vector;

// Clarify
// 1. does this linked-list have loop ?
// 2. if head is nullptr, what should return ? or i can assume this head would always has node
// 3. how many number of node is this linked list maximum ?

ListNode *Solution::removeNthFromEnd(ListNode *head, int n) {
	ListNode *dummy = new ListNode(0, head);
	ListNode *first = head;
	ListNode *second = head;
	for (int i = 0; i < n; ++i) {
		first = first->next;
	}

	while (first->next) {
		first = first->next;
		second = second->next;
	}
	second->next = second->next->next;
	return dummy->next;
}
