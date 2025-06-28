#include <Solution.h>

Node* Solution::flipBinaryTree(Node* root, Node * leaf) {
	Node* prev = nullptr;
	auto cur = leaf;

	while (cur) {
		auto parent = cur->parent;

		if (cur->left) {
			cur->right = cur->left;
		}
		cur->left = parent;
		if (parent) {
			if (parent->left == cur) parent->left = nullptr;
			else parent->right = nullptr;
		}

		cur->parent = prev;
		prev = cur;
		cur = parent;
	}
	return leaf;
}
