#include <Solution.h>
#include <iostream>
#include <climits>


using std::abs;

void dfs(TreeNode* node, int& result, double target) {
	if (!node) return;

	if (abs(target - (double)node->val) < abs(target - (double)result)) {
		result = node->val;
	}

	dfs(node->left, result, target);
	dfs(node->right, result, target);
}

int Solution::closestValue2(TreeNode* root, double target) {
	int result = INT_MAX;
	dfs(root, result, target);
	return result;
}
