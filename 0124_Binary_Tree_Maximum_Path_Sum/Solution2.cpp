#include <Solution.h>
#include <iostream>
#include <algorithm>
#include <climits>

using std::max;

int dfs(TreeNode* node, int& result) {
	if (!node) return 0;
	int maxSum = node->val;

	int leftSum = dfs(node->left, result);
	int rightSum = dfs(node->right, result);

	int connectSum = maxSum + leftSum + rightSum;
	result = max(result, connectSum);

	int maxSub = max(leftSum, rightSum);
	if (maxSub > 0) {
		maxSum = maxSum + maxSub;
	}
	result = max(result, maxSum);
	return maxSum;
}

int Solution::maxPathSum2(TreeNode* root) {
	int result(INT_MIN);
	dfs(root, result);
	return result;
}
