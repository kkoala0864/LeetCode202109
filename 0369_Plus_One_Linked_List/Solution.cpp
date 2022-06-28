#include <Solution.h>
#include <iostream>
#include <stack>

using std::stack;

ListNode* Solution::plusOne(ListNode* head) {
	stack<ListNode*> st;
	ListNode* it = head;
	while (it) {
		st.emplace(it);
		it = it->next;
	}
	int carry = 1;
	int val = 0;
	while (carry && !st.empty()) {
		val = st.top()->val + 1;
		carry = val / 10;
		st.top()->val = val % 10;
		st.pop();
	}
	if (st.empty() && carry > 0) {
		ListNode* newHead = new ListNode(carry, head);
		head = newHead;
	}
	return head;
}
