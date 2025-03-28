#include <Solution.h>
#include <iostream>
#include <stack>
using std::stack;

ListNode *Solution::deleteDuplicates2(ListNode *head) {
	if (!head)
		return head;
	stack<ListNode *> st;
	ListNode *iter = head;
	while (iter) {
		if (!st.empty() && iter->val == st.top()->val) {
			while (iter && iter->val == st.top()->val) {
				iter = iter->next;
			}
			st.pop();
			if (!st.empty()) {
				st.top()->next = iter;
			} else if (iter) {
				head = iter;
				st.emplace(iter);
				iter = iter->next;
			}
		} else {
			st.emplace(iter);
			iter = iter->next;
		}
	}
	return st.empty() ? nullptr : head;
}
