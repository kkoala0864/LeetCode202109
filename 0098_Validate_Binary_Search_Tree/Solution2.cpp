#include <Solution.h>
#include <iostream>
#include <climits>

bool check(TreeNode* root, int minVal, int maxVal) {
	if (!root) return true;

	if (root->val <= minVal || root->val >= maxVal) {
		return false;
	}
	return check(root->left, INT_MIN, root->val) && check(root->right, root->val, INT_MAX);
}

bool Solution::isValidBST2(TreeNode* root) {
	return check(root, LONG_MIN, LONG_MAX);
}

