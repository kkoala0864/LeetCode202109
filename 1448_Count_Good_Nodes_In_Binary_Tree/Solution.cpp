#include <Solution.h>
#include <iostream>
#include <algorithm>
#include <climits>

using std::max;

void dfs(TreeNode* node, int val, int& result) {
	if (!node) return;
	if (node->val >= val) ++result;

	int nVal = max(val, node->val);
	if (node->left) dfs(node->left, nVal, result);
	if (node->right) dfs(node->right, nVal, result);
}

int Solution::goodNodes(TreeNode* root) {
	int result = 0;
	dfs(root, INT_MIN, result);
	return result;
}
