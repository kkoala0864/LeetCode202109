#include <Solution.h>
#include <iostream>

int dfs2(TreeNode *node, int &result) {
	if (!node)
		return 0;

	node->val += dfs2(node->left, result);
	node->val += dfs2(node->right, result);

	result += abs(node->val - 1);

	return node->val - 1;
}

int Solution::distributeCoins2(TreeNode *root) {
	int result = 0;
	dfs2(root, result);
	return result;
}
