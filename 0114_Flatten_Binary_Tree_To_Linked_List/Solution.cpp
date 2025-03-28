#include <Solution.h>
#include <iostream>

TreeNode *flattenTree(TreeNode *node) {
	if (!node)
		return nullptr;
	if (!node->left && !node->right)
		return node;

	TreeNode *leftEnd = flattenTree(node->left);
	TreeNode *rightEnd = flattenTree(node->right);
	if (leftEnd) {
		leftEnd->right = node->right;
		node->right = node->left;
		node->left = nullptr;
	}
	return rightEnd == nullptr ? leftEnd : rightEnd;
}

void Solution::flatten(TreeNode *root) {
	flattenTree(root);
}
