#include <Solution.h>
#include <iostream>

void processChild(Node *node, Node *&prev, Node *&leftMost) {
	if (!node)
		return;
	if (prev) {
		prev->next = node;
	} else {
		leftMost = node;
	}
	prev = node;
}

Node *Solution::connect(Node *root) {
	if (!root)
		return nullptr;
	Node *leftMost = root;
	Node *prev = nullptr;
	Node *cur = nullptr;

	while (leftMost) {
		prev = nullptr;
		cur = leftMost;

		leftMost = nullptr;
		while (cur) {
			processChild(cur->left, prev, leftMost);
			processChild(cur->right, prev, leftMost);
			cur = cur->next;
		}
	}
	return root;
}
