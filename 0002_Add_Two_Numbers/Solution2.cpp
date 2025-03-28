#include <Solution.h>
#include <iostream>
#include <queue>

using std::queue;

ListNode *Solution::addTwoNumbers2(ListNode *l1, ListNode *l2) {
	int carry = 0;
	ListNode *result = new ListNode();
	ListNode *iter = result;
	while (l1 || l2) {
		int val = carry;
		if (l1) {
			val += l1->val;
			l1 = l1->next;
		}
		if (l2) {
			val += l2->val;
			l2 = l2->next;
		}
		iter->next = new ListNode(val % 10);
		carry = val / 10;
		iter = iter->next;
	}

	if (carry > 0)
		iter->next = new ListNode(carry);
	return result->next;
}
