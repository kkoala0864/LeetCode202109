#include <Solution.h>
#include <iostream>
#include <algorithm>
#include <climits>

using std::min;

void dfs(TreeNode *node, int &last, int &result) {
	if (!node)
		return;
	dfs(node->left, last, result);
	result = min(result, abs(node->val - last));
	last = node->val;
	dfs(node->right, last, result);
}

int Solution::minDiffInBST(TreeNode *root) {
	int result = INT_MAX;
	int last = INT_MAX;
	dfs(root, last, result);
	return result;
}
