#include <Solution.h>
#include <iostream>

Node *Solution::flatten(Node *head) {
	if (!head)
		return nullptr;

	Node *ci = nullptr;
	if (head->child) {
		ci = flatten(head->child);
		head->child = nullptr;
	}
	Node *ni = flatten(head->next);
	if (ci) {
		head->next = ci;
		ci->prev = head;
		while (ci->next)
			ci = ci->next;
		ci->next = ni;
		if (ni)
			ni->prev = ci;
	} else {
		head->next = ni;
		if (ni)
			ni->prev = head;
	}
	return head;
}
