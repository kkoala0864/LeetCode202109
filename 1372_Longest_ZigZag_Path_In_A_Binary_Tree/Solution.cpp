#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::max;

int dfs(TreeNode *node, int side, int &result) {
	if (!node)
		return 0;
	int left = dfs(node->left, 0, result) + 1;
	int right = dfs(node->right, 1, result) + 1;
	result = max({result, left, right});
	return side == 0 ? right : left;
}

int Solution::longestZigZag(TreeNode *root) {
	int result = 0;
	return max({dfs(root, 0, result), dfs(root, 1, result), result}) - 1;
}
