#include <Solution.h>
#include <iostream>

// Clarify : Does the list can start from non-leaf node ?
// the number is unique?

// 1. contruct link from client to parent node and record the leaf node
// 2. greedy algorithm from leaf node

int DFS(TreeNode* node, int& result) {
	if (!node) return 0;
	if (!node->left && !node->right) {
		result = max(result, node->val);
		return node->val;
	}

	int sum(node->val);
	int leftMaxSum = dfs(node->left, result);
	int rightMaxSum = dfs(node->right, result);

	if (leftMaxSum > 0) sum += leftMaxSum;
	if (rightMaxSum > 0) sum += rightMaxSum;

	result = max(result, sum);

	int childSum = max(leftMaxSum, rightMaxSum);
	return childSum > 0 ? childSum + node->val : node->val;
}

int Solution::maxPathSum(TreeNode* root) {
	int result(INT_MIN);
	DFS(root, result);
	return result;
}
