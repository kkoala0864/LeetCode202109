#include <Solution.h>
#include <iostream>

bool Cmp(TreeNode *node, TreeNode *subnode) {
	if (!node) {
		if (!subnode)
			return true;
		else
			return false;
	} else {
		if (subnode && node->val == subnode->val) {
			return Cmp(node->left, subnode->left) && Cmp(node->right, subnode->right);
		} else
			return false;
	}
}

bool Solution::isSubtree(TreeNode *root, TreeNode *subRoot) {
	if (!root)
		return false;
	if (Cmp(root, subRoot))
		return true;
	return (isSubtree(root->left, subRoot)) || (isSubtree(root->right, subRoot));
}
