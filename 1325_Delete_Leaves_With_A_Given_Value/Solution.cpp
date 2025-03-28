#include <Solution.h>
#include <iostream>

bool dfs(TreeNode *node, int target) {
	if (!node)
		return false;

	if (node->left) {
		if (dfs(node->left, target))
			node->left = nullptr;
	}
	if (node->right) {
		if (dfs(node->right, target))
			node->right = nullptr;
	}
	return !node->left && !node->right && node->val == target;
}

TreeNode *Solution::removeLeafNodes(TreeNode *root, int target) {
	TreeNode *dummy = new TreeNode(-1);
	dummy->left = root;

	dfs(dummy, target);
	return dummy->left;
}
