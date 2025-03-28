#include <Solution.h>
#include <iostream>

bool compare(TreeNode *lhs, TreeNode *rhs) {
	if (!lhs && !rhs)
		return true;
	if ((lhs && !rhs) || (!lhs && rhs))
		return false;
	if (lhs->val != rhs->val)
		return false;
	return compare(lhs->left, rhs->right) && compare(lhs->right, rhs->left);
}

bool Solution::isSymmetric2(TreeNode *root) {
	return compare(root->left, root->right);
}
