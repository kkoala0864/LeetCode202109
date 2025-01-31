#include <Solution.h>
#include <iostream>
#include <algorithm>
#include <climits>
using std::max;

// Clarify : Does the list can start from non-leaf node ?
// the number is unique?

// 1. contruct link from client to parent node and record the leaf node
// 2. greedy algorithm from leaf node

int dfs(TreeNode* node, int& result) {
	if (!node) return 0;
	int lv = dfs(node->left, result);
	int rv = dfs(node->right, result);
	int cur = node->val;
	if (lv > 0) {
		cur += lv;
	}
	if (rv > 0) {
		cur += rv;
	}
	result = max(result, cur);
	int child = max({lv, rv, 0});
	return node->val + child;
}

int Solution::maxPathSum(TreeNode* root) {
	if (!root) return 0;
	int result = INT_MIN;
	dfs(root, result);
	return result;
}
