#include <Solution.h>
#include <iostream>
#include <algorithm>
#include <climits>

using std::max;

int dfs2(TreeNode* node, int& result) {
	if (!node) return 0;
	int l = dfs2(node->left, result);
	int r = dfs2(node->right, result);

	result = max(l + r + 1, result);
	return max(l, r) + 1;
}

int Solution::diameterOfBinaryTree3(TreeNode* root) {
	if (!root) return 0;
	int result = 0;
	dfs2(root, result);
	return result;
}
