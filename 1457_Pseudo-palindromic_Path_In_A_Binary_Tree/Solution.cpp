#include <Solution.h>
#include <iostream>

void dfs(TreeNode *node, int bitmask, int &result) {
	if (!node)
		return;
	bitmask ^= 1 << node->val;

	if (!node->left && !node->right) {
		int cnt = 0;
		while (bitmask) {
			bitmask &= (bitmask - 1);
			++cnt;
		}
		if (cnt < 2)
			++result;
		return;
	}

	if (node->left)
		dfs(node->left, bitmask, result);
	if (node->right)
		dfs(node->right, bitmask, result);
}

int Solution::pseudoPalindromicPaths(TreeNode *root) {
	int bitmask = 0;
	int result = 0;
	dfs(root, bitmask, result);
	return result;
}
