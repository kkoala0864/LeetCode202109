#include <Solution.h>
#include <iostream>
#include <vector>

using std::vector;

ListNode* Solution::removeNthFromEnd2(ListNode* head, int n) {
	if (!head) return head;
	ListNode* dummy = new ListNode(0, head);
	ListNode* first = dummy;
	ListNode* second = dummy;
	for (int i = 0 ; i < n ; ++i) {
		first = first->next;
	}

	while (first->next) {
		first = first->next;
		second = second->next;
	}
	second->next = second->next->next;
	return dummy->next;
}
