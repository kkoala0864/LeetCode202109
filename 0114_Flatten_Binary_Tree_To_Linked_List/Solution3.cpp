#include <Solution.h>
#include <iostream>

TreeNode *dfs(TreeNode *node) {
	if (!node)
		return node;

	auto le = dfs(node->left);
	auto re = dfs(node->right);

	if (le) {
		le->right = node->right;
		node->right = node->left;
		node->left = nullptr;
	}

	return re ? re : le ? le
	                    : node;
}

void Solution::flatten3(TreeNode *root) {
	dfs(root);
}
