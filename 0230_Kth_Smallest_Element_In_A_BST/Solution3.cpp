#include <Solution.h>
#include <iostream>

void dfs(TreeNode *node, int &k, int &result) {
	if (!node)
		return;
	dfs(node->left, k, result);
	--k;
	if (k == 0)
		result = node->val;
	if (k <= 0)
		return;
	dfs(node->right, k, result);
}

int Solution::kthSmallest3(TreeNode *root, int k) {
	int result = 0;
	dfs(root, k, result);
	return result;
}
