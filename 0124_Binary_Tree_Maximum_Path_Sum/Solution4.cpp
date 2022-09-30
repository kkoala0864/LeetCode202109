#include <Solution.h>
#include <iostream>
#include <algorithm>
#include <climits>

using std::max;

int dfs4(TreeNode* node, int& result) {
	if (!node) return 0;

	int lr = dfs4(node->left, result);
	int rr = dfs4(node->right, result);

	int childMax = max({0, lr, rr});

	if (lr > 0 && rr > 0) result = max(result, lr + rr + node->val);
	result = max(result, childMax + node->val);
	return childMax + node->val;
}

int Solution::maxPathSum4(TreeNode* root) {
	int result = INT_MIN;
	dfs4(root, result);
	return result;
}
