#include <Solution.h>
#include <iostream>

void dfs(TreeNode* node, int preSum, int& result) {
	if (!node) return;
	preSum = preSum * 10 + node->val;
	if (!node->left && !node->right) {
		result += preSum;
	}
	dfs(node->left, preSum, result);
	dfs(node->right, preSum, result);
}

int Solution::sumNumbers(TreeNode* root) {
	int result = 0;
	dfs(root, 0, result);
	return result;
}
