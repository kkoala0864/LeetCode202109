#include <Solution.h>
#include <iostream>

ListNode* merge2(ListNode* l, ListNode* r) {
	if (!l) return r;
	if (!r) return l;
	ListNode* result = new ListNode();
	ListNode* it = result;
	while (l && r) {
		if (l->val < r->val) {
			it->next = l;
			l = l->next;
		} else {
			it->next = r;
			r = r->next;
		}
		it = it->next;
	}
	if (l) it->next = l;
	if (r) it->next = r;
	return result->next;
}

ListNode* divide2(ListNode* head, int n) {
	if (n <= 1) return head;

	int half = n / 2;
	ListNode* it = head;
	while (--half) it = it->next;
	ListNode* rightHead = it->next;
	it->next = nullptr;

	return merge2(divide2(head, n/2), divide2(rightHead, n - (n/2)));
}

ListNode* Solution::sortList2(ListNode* head) {
	int n = 0;
	ListNode *it = head;
	while (it) {
		++n;
		it = it->next;
	}
	return divide2(head, n);
}
