#include <Solution.h>
#include <iostream>

TreeNode* dfs(TreeNode* root) {
	if (!root) return nullptr;
	if (!root->left && !root->right) return root;
	TreeNode* llast = dfs(root->left);
	TreeNode* rlast = dfs(root->right);

	if (llast) llast->right = root->right;
	if (root->left) root->right = root->left;
	root->left = nullptr;
	return rlast ? rlast : llast;
}

void Solution::flatten3(TreeNode* root) {
	dfs(root);
}
