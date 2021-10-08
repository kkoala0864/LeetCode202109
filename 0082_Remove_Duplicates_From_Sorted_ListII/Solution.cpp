#include <Solution.h>
#include <iostream>
#include <stack>

using std::stack;

// [ 1 1 2 3 4 5 6 ]
// st : [ 2 3 4 5 6 ]
// [ 1 2 3 3 4 4 5 ]
// st : [ 1 2 3 
//

ListNode* Solution::deleteDuplicates(ListNode* head) {
	if (!head || !head->next) return head;
	ListNode* node = deleteDuplicates(head->next);
	if (head->val != head->next->val) {
		head->next = node;
		return head;
	} else {
		ListNode* iter = node;
		while (iter && head->val == iter->val) {
			iter = iter->next;
		}
		return iter;
	}
}

/*
ListNode* Solution::deleteDuplicates(ListNode* head) {
	if (!head || !head->next) return head;

	stack<ListNode*> st;
	ListNode* iter = head;

	while (iter) {
		if (st.empty()) {
			head = iter;
			st.emplace(iter);
			iter = iter->next;
		} else if (iter->val != st.top()->val) {
			st.top()->next = iter;
			st.emplace(iter);
			iter = iter->next;
		} else {
			while (iter && (iter->val == st.top()->val)) iter = iter->next;
			st.pop();
		}
	}
	if (st.empty()) return nullptr;
	else st.top()->next = iter;
	return head;
}
*/
