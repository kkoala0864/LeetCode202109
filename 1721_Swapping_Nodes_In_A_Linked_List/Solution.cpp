#include <Solution.h>
#include <iostream>

using std::swap;

ListNode *Solution::swapNodes(ListNode *head, int k) {
	ListNode *one = head;
	while (--k) {
		one = one->next;
	}
	ListNode *swapOne = one;
	ListNode *two = head;
	while (one->next) {
		one = one->next;
		two = two->next;
	}
	swap(two->val, swapOne->val);
	return head;
}
