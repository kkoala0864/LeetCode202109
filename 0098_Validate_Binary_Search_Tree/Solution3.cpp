#include <Solution.h>
#include <iostream>
#include <climits>

bool check2(TreeNode* node, long leftVal, long rightVal) {
	if (!node) return true;
	if (node->val <= leftVal || node->val >= rightVal) return false;

	return check2(node->left, leftVal, node->val) && check2(node->right, node->val, rightVal);
}

bool Solution::isValidBST3(TreeNode* root) {
	return check2(root, LONG_MIN, LONG_MAX);
}

