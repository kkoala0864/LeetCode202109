#include <Solution.h>
#include <iostream>

bool dfs(TreeNode *node) {
	if (!node)
		return false;

	bool l = dfs(node->left);
	bool r = dfs(node->right);

	if (!l)
		node->left = nullptr;
	if (!r)
		node->right = nullptr;

	return node->val == 1 ? true : l || r;
}

TreeNode *Solution::pruneTree(TreeNode *root) {
	if (!root)
		return root;
	if (!dfs(root))
		return nullptr;
	return root;
}
