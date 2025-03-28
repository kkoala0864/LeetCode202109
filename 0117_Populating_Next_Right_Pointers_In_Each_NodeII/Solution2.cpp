#include <Solution.h>
#include <iostream>

Node *Solution::connect2(Node *root) {
	Node *head = root, *iter = head, *nextHead = nullptr, *append = nullptr;

	while (head) {
		iter = head;
		while (iter) {
			if (iter->left || iter->right) {
				if (iter->left && iter->right)
					iter->left->next = iter->right;
				if (!nextHead)
					nextHead = iter->left ? iter->left : iter->right;
				if (!append)
					append = iter->left ? iter->left : iter->right;
				else {
					while (append->next)
						append = append->next;
					append->next = iter->left ? iter->left : iter->right;
				}
			}
			iter = iter->next;
		}
		head = nextHead;
		nextHead = nullptr;
		append = nullptr;
	}
	return root;
}
