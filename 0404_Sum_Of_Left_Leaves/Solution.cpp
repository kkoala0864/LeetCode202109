#include <Solution.h>
#include <iostream>

int dfs(TreeNode* node) {
	if (!node) return 0;
	int right = dfs(node->right);
	if (!node->left) return right;
	if (!node->left->left && !node->left->right) return node->left->val + right;
	else return dfs(node->left) + right;
}

int Solution::sumOfLeftLeaves(TreeNode* root) {
	return dfs(root);
}
