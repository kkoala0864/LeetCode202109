#include <Solution.h>
#include <iostream>

bool cmp(TreeNode *node, TreeNode *subRoot) {
	if (!node && !subRoot)
		return true;
	if (!node || !subRoot)
		return false;
	if (node->val != subRoot->val)
		return false;
	return cmp(node->left, subRoot->left) && cmp(node->right, subRoot->right);
}

bool Solution::isSubtree2(TreeNode *root, TreeNode *subRoot) {
	if (cmp(root, subRoot))
		return true;
	if (root)
		return isSubtree2(root->left, subRoot) || isSubtree2(root->right, subRoot);
	return false;
}
