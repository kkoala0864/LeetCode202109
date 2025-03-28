#include <Solution.h>
#include <iostream>

void dfs(TreeNode *node, int &result) {
	if (!node)
		return;

	if (!node->left && !node->right) {
		result += node->val;
		return;
	}

	dfs(node->left, result);
	if (node->right && (node->right->left || node->right->right))
		dfs(node->right, result);
}

int Solution::sumOfLeftLeaves(TreeNode *root) {
	int result = 0;
	if (!root->left && !root->right)
		return 0;
	dfs(root, result);
	return result;
}
