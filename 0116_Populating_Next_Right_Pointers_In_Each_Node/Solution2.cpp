#include <Solution.h>
#include <iostream>
#include <queue>

using std::queue;

Node *Solution::connectNoSpace(Node *root) {
	if (!root || !root->left)
		return root;

	root->left->next = root->right;
	Node *leftRight = root->left;
	Node *rightLeft = root->right;
	while (leftRight->right) {
		leftRight = leftRight->right;
		rightLeft = rightLeft->left;
		leftRight->next = rightLeft;
	}
	connectNoSpace(root->left);
	connectNoSpace(root->right);
	return root;
}

Node *Solution::connect2(Node *root) {
	if (!root)
		return root;
	queue<Node *> que, next;
	que.emplace(root);
	while (!que.empty()) {
		Node *cur = que.front();
		que.pop();
		if (cur->left) {
			cur->left->next = cur->right;
			next.emplace(cur->left);
			next.emplace(cur->right);
			if (!que.empty())
				cur->right->next = que.front()->left;
		}
		if (que.empty())
			que = move(next);
	}
	return root;
}
