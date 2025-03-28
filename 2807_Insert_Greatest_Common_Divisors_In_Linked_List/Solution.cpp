#include <Solution.h>
#include <iostream>

using std::swap;

int getGCD(int lhs, int rhs) {
	if (lhs < rhs)
		swap(lhs, rhs);
	if (rhs == 0)
		return lhs;

	lhs %= rhs;
	return getGCD(rhs, lhs);
}

ListNode *Solution::insertGreatestCommonDivisors(ListNode *head) {
	ListNode *iter = head;
	while (iter->next) {
		int gcd = getGCD(iter->val, iter->next->val);
		ListNode *g = new ListNode(gcd, iter->next);
		iter->next = g;
		iter = g->next;
	}
	return head;
}
