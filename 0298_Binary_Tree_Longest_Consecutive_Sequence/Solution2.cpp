#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::max;

void dfs(TreeNode *node, int local, int &result) {
	if (!node) {
		result = max(result, local);
		return;
	}

	if (node->left && node->left->val - node->val == 1) {
		dfs(node->left, local + 1, result);
	} else {
		result = max(result, local);
		dfs(node->left, 1, result);
	}

	if (node->right && node->right->val - node->val == 1) {
		dfs(node->right, local + 1, result);
	} else {
		result = max(result, local);
		dfs(node->right, 1, result);
	}
}

int Solution::longestConsecutive2(TreeNode *root) {
	int result = 0;
	dfs(root, 1, result);
	return result;
}
