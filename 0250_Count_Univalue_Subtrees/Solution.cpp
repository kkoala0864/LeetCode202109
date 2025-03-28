#include <Solution.h>
#include <iostream>

bool dfs(TreeNode *node, int &result) {
	if (!node)
		return true;

	int lv = node->left ? node->left->val : node->val;
	int rv = node->right ? node->right->val : node->val;

	bool lr = dfs(node->left, result);
	bool rr = dfs(node->right, result);

	if ((lr && rr) && (lv == node->val && rv == node->val)) {
		++result;
		return true;
	}
	return false;
}

int Solution::countUnivalSubtrees(TreeNode *root) {
	int result = 0;
	dfs(root, result);
	return result;
}
