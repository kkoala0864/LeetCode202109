#include <Solution.h>
#include <iostream>
#include <stack>

ListNode* Solution::addTwoNumbers(ListNode* l1, ListNode* l2) {
	stack<int> s1, s2;
	auto iter = l1;
	while (iter) {
		s1.emplace(iter->val);
		iter = iter->next;
	}
	iter = l2;
	while (iter) {
		s2.emplace(iter->val);
		iter = iter->next;
	}

	iter = nullptr;
	int carry = 0;
	while (!s1.empty() || !s2.empty()) {
		int v1 = !s1.empty() ? s1.top() : 0;
		int v2 = !s2.empty() ? s2.top() : 0;
		if (!s1.empty()) {
			s1.pop();
		}
		if (!s2.empty()) {
			s2.pop();
		}
		int v = v1 + v2 + carry;
		carry = v / 10;
		v %= 10;
		ListNode* cur = new ListNode(v, iter);
		iter = cur;
	}
	if (carry > 0) {
		ListNode* cur = new ListNode(carry, iter);
		iter = cur;
	}
	return iter;
}
