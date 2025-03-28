#include <Solution.h>
#include <iostream>

TreeNode *flat(TreeNode *node) {
	if (!node)
		return node;

	TreeNode *left = flat(node->left);
	TreeNode *right = flat(node->right);
	node->left = nullptr;
	if (left) {
		node->right = left;
		while (left->right)
			left = left->right;
		left->right = right;
	}
	return node;
}

void Solution::flatten2(TreeNode *root) {
	flat(root);
}
