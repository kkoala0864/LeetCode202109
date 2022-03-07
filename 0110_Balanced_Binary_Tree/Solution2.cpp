#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::max;

int iterate(TreeNode* node, bool& result) {
	if (!node) return 0;
	if (!result) return 0;
	int LH = iterate(node->left, result);
	int RH = iterate(node->right, result);
	if (abs(LH-RH) > 1) result = false;

	return max(LH, RH) + 1;
}

bool Solution::isBalanced2(TreeNode* root) {
	bool result = true;
	iterate(root, result);
	return result;
}
