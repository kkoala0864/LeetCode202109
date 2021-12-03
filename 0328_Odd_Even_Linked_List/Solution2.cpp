#include <Solution.h>
#include <iostream>

ListNode* Solution::oddEvenList2(ListNode* head) {
	if (!head || !head->next) return head;

	ListNode* odd = head;
	ListNode* even = head->next;

	ListNode* add = odd;
	ListNode* beAdd = even;
	while (beAdd) {
		add->next = beAdd->next;
		add = add->next;
		swap(add, beAdd);
	}

	ListNode* iter = odd;
	while (iter->next) {
		iter = iter->next;
	}
	iter->next = eveb;
	return head;
}
