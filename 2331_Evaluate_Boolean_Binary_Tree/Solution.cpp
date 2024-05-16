#include <Solution.h>
#include <iostream>

bool Solution::evaluateTree(TreeNode* root) {
	if (!root) return true;
	if (!root->left && !root->right) return root->val;
	if (root->val == 2) {
		return evaluateTree(root->left) || evaluateTree(root->right);
	} else if (root->val == 3) {
		return evaluateTree(root->left) && evaluateTree(root->right);
	}
	return true;
}
