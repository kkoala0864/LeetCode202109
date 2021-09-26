#include <Solution.h>
#include <iostream>
#include <stack>

using std::stack;

void Solution::reorderList(ListNode* head) {
	ListNode* slow = head;
	ListNode* fast = head;
	stack<ListNode*> st;
	while (fast && fast->next) {
		st.emplace(slow);
		slow = slow->next;
		fast = fast->next->next;
	}

	ListNode* start = slow->next;
	slow->next = nullptr;
	if (!fast) st.pop();
	while (start) {
		ListNode* tmp = start->next;
		start->next = st.top()->next;
		st.top()->next = start;
		st.pop();
		start = tmp;
	}
}
