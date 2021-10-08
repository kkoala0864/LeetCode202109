#include <Solution.h>
#include <iostream>

ListNode* Solution::oddEvenList(ListNode* head) {
	if (!head || !head->next) return head;
	ListNode* odd = head;
	ListNode* event = head->next;

	ListNode* add = odd;
	ListNode* beAdd = event;

	while (beAdd) {
		add->next = beAdd->next;
		add = add->next;
		swap(add, beAdd);
	}
	ListNode* iter = odd;
	while (iter->next) {
		iter = iter->next;
	}
	iter->next = event;
	return odd;
}
