#include <Solution.h>
#include <iostream>

ListNode *Solution::mergeInBetween(ListNode *list1, int a, int b, ListNode *list2) {
	ListNode *dummy = new ListNode(0, list1);
	ListNode *iter = dummy;

	while (a--) {
		iter = iter->next;
		--b;
	}
	ListNode *tmp = iter->next;
	iter->next = list2;
	iter = tmp;
	while (b--) {
		iter = iter->next;
	}
	tmp = list2;
	while (tmp->next) {
		tmp = tmp->next;
	}
	tmp->next = iter->next;
	iter->next = nullptr;
	return dummy->next;
}
