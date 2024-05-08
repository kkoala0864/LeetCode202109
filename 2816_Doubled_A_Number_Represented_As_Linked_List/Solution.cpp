#include <Solution.h>
#include <iostream>
#include <stack>

using std::stack;

ListNode* Solution::doubleIt(ListNode* head) {
	ListNode* iter = head;
	stack<ListNode*> st;

	while (iter) {
		st.emplace(iter);
		iter = iter->next;
	}

	int carry = 0;
	while (!st.empty()) {
		ListNode* cur = st.top();
		st.pop();
		int v = cur->val;
		cur->val = ((v * 2) + carry) % 10;
		carry = (v * 2) / 10;
	}
	if (carry) {
		ListNode* node = new ListNode(carry, head);
		head = node;
	}
	return head;

}
