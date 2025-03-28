#include <Solution.h>
#include <iostream>

int dfs(TreeNode *node, int &result) {
	if (!node)
		return 0;

	int lr = dfs(node->left, result);
	int rr = dfs(node->right, result);

	result += (abs(lr) + abs(rr));

	return node->val + lr + rr - 1;
}

int Solution::distributeCoins(TreeNode *root) {
	int result = 0;
	dfs(root, result);
	return result;
}
