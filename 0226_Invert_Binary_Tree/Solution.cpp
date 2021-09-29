#include <Solution.h>
#include <iostream>

TreeNode* Solution::invertTree(TreeNode* root) {
	if (!root) return root;
	TreeNode* tmp = invertTree(root->left);
	root->left = invertTree(root->right);
	root->right = tmp;
	return root;
}
