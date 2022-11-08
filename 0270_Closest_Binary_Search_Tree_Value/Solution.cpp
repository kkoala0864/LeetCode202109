#include <Solution.h>
#include <iostream>
#include <climits>

void dfs(TreeNode* node, const double& target, int& result) {
	if (!node) return;
	dfs(node->left, target, result);
	if (abs(target - (double)node->val) < abs(target - result)) {
		result = node->val;
	} else {
		return;
	}

	dfs(node->right, target, result);
}

int Solution::closestValue(TreeNode* root, double target) {
	int result = INT_MAX;
	dfs(root, target, result);
	return result;
}
