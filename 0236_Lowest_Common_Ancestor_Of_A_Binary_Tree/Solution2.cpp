#include <Solution.h>
#include <iostream>

TreeNode *Solution::lowestCommonAncestor2(TreeNode *root, TreeNode *p, TreeNode *q) {
	if (!root)
		return nullptr;
	if (root == p || root == q)
		return root;
	TreeNode *left = lowestCommonAncestor2(root->left, p, q);
	TreeNode *right = lowestCommonAncestor2(root->right, p, q);
	if (left && right)
		return root;
	return left ? left : right;
}
