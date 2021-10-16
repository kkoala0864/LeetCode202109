#include <Solution.h>
#include <iostream>
#include <algorithm>
using std::max;

int compare(TreeNode* node, bool& isBalance) {
	if (!node) return 0;

	int left = compare(node->left, isBalance);
	int right = compare(node->right, isBalance);
	if (abs(left - right) > 1) isBalance = false;
	return max(left, right) + 1;
}

bool Solution::isBalanced(TreeNode* root) {
	if (!root) return true;
	bool isBalance = true;
	compare(root, isBalance);
	return isBalance;
}
