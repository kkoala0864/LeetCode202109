#include <Solution.h>
#include <iostream>

Node* Solution::insert(Node* head, int insertVal) {
	if (!head) {
		head = new Node(insertVal);
		head->next = head;
		return head;
	}

	Node* iter = head;
	while (iter->next != head) {
		if ((iter->val < iter->next->val && iter->val <= insertVal && iter->next->val >= insertVal) ||
		   (iter->val > iter->next->val && (insertVal >= iter->val || insertVal <= iter->next->val))) {
			break;
		}
		iter = iter->next;
	}
	Node* node = new Node(insertVal, iter->next);
	iter->next = node;
	return head;
}
