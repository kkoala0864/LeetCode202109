#include <Solution.h>
#include <iostream>
#include <stack>

using std::stack;

ListNode* Solution::deleteDuplicates3(ListNode* head) {
	if (!head) return nullptr;

	ListNode* next = head->next;
	while (next && head->val == next->val) next = next->next;

	if (head->next == next) {
		head->next = deleteDuplicates3(next);
		return head;
	} else {
		return deleteDuplicates3(next);
	}
}

