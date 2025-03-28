#include <Solution.h>
#include <iostream>

void dfs(TreeNode *node, int low, int high, int &result) {
	if (!node)
		return;
	if (low <= node->val && node->val <= high) {
		result += node->val;
	}
	dfs(node->left, low, high, result);
	dfs(node->right, low, high, result);
}

int Solution::rangeSumBST(TreeNode *root, int low, int high) {
	int result = 0;
	dfs(root, low, high, result);
	return result;
}
