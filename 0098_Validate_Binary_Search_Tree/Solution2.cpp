#include <Solution.h>
#include <iostream>
#include <climits>

bool check(TreeNode* root, long minVal, long maxVal) {
	if (!root) return true;

	if (root->val <= minVal || root->val >= maxVal) {
		return false;
	}
	return check(root->left, LONG_MIN, root->val) && check(root->right, root->val, LONG_MAX);
}

bool Solution::isValidBST2(TreeNode* root) {
	return check(root, LONG_MIN, LONG_MAX);
}

