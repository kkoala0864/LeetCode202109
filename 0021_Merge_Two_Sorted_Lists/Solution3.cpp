#include <Solution.h>
#include <iostream>

using namespace std;

ListNode *Solution::mergeTwoLists3(ListNode *l1, ListNode *l2) {
	if (!l1)
		return l2;
	if (!l2)
		return l1;

	ListNode *head = nullptr, *iter = nullptr;
	if (l1->val < l2->val) {
		head = iter = l1;
		l1 = l1->next;
	} else {
		head = iter = l2;
		l2 = l2->next;
	}

	while (l1 && l2) {
		if (l1->val < l2->val) {
			iter->next = l1;
			l1 = l1->next;
			iter = iter->next;
			while (l1 && l1->val < l2->val) {
				l1 = l1->next;
				iter = iter->next;
			}
		} else {
			iter->next = l2;
			l2 = l2->next;
			iter = iter->next;
			while (l2 && l1->val >= l2->val) {
				l2 = l2->next;
				iter = iter->next;
			}
		}
	}
	if (l1)
		iter->next = l1;
	else if (l2)
		iter->next = l2;

	return head;
}
