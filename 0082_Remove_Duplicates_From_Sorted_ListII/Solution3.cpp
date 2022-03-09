#include <Solution.h>
#include <iostream>
#include <stack>

using std::stack;

ListNode* Solution::deleteDuplicates3(ListNode* head) {
	if (!head) return head;
	stack<ListNode*> st;
	st.emplace(head);
	ListNode* iter = head->next;
	while (iter) {
		if (st.top()->val != iter->val) {
			st.emplace(iter);
			iter = iter->next;
		} else {
			while (iter && st.top()->val == iter->val) iter = iter->next;

			st.pop();
			if (!st.empty()) st.top()->next = iter;
			else head = iter;

			if (iter) {
				st.emplace(iter);
				iter = iter->next;
			}
		}
	}
	return head;
}

