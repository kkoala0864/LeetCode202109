#include <Solution.h>
#include <iostream>

void recur(TreeNode *node, int depth, int val) {
	if (!node)
		return;
	if (depth == 1) {
		node->left = new TreeNode(val, node->left, nullptr);
		node->right = new TreeNode(val, nullptr, node->right);
		return;
	}

	depth -= 1;
	recur(node->left, depth, val);
	recur(node->right, depth, val);
}

TreeNode *Solution::addOneRow(TreeNode *root, int val, int depth) {
	if (!root)
		return nullptr;
	if (depth == 1)
		return new TreeNode(val, root, nullptr);

	recur(root, depth - 1, val);
	return root;
}
