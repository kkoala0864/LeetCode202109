#include <Solution.h>
#include <iostream>

Node *Solution::connect3(Node *root) {
	Node *head = root, *iter = nullptr, *nextHead = nullptr, *nextIter = nullptr;

	while (head) {
		iter = head;
		while (iter) {
			if (iter->left && iter->right)
				iter->left->next = iter->right;
			if (nextHead == nullptr) {
				nextHead = iter->left ? iter->left : iter->right;
				nextIter = nextHead;
			} else {
				if (iter->left || iter->right) {
					while (nextIter->next) {
						nextIter = nextIter->next;
					}
					nextIter->next = iter->left ? iter->left : iter->right;
				}
			}
			iter = iter->next;
		}
		head = nextHead;
		nextHead = nullptr;
		nextIter = nullptr;
	}
	return root;
}
