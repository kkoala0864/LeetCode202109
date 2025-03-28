#include <Solution.h>
#include <iostream>

Node *Solution::connect3(Node *root) {
	Node *head = root, *iter = head;
	while (head) {
		iter = head;
		if (iter->left) {
			while (iter) {
				iter->left->next = iter->right;
				if (iter->next) {
					iter->right->next = iter->next->left;
				}
				iter = iter->next;
			}
		}
		head = head->left;
	}
	return root;
}
