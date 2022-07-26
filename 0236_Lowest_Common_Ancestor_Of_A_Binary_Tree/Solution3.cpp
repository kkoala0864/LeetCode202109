#include <Solution.h>
#include <iostream>

TreeNode* Solution::lowestCommonAncestor3(TreeNode* root, TreeNode* p, TreeNode* q) {
	if (!root) return nullptr;
	if (p == root || q == root) return root;
	TreeNode* left = lowestCommonAncestor3(root->left, p, q);
	TreeNode* right = lowestCommonAncestor3(root->right, p, q);
	if (left && right) return root;
	return left ? left : right;
}

