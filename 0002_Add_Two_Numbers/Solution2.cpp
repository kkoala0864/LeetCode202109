#include <Solution.h>
#include <iostream>
#include <queue>

using std::queue;

ListNode* Solution::addTwoNumbers2(ListNode* l1, ListNode* l2) {
	int carry = 0;
	ListNode* head = nullptr, *iter = nullptr;
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
		carry = val / 10;
		val %= 10;
		if (!head) {
			head = new ListNode(val);
			iter = head;
		} else {
			ListNode* node = new ListNode(val);
			iter->next = node;
			iter = iter->next;
		}
	}
	if (carry > 0) iter->next = new ListNode(carry);
	return head;
}
