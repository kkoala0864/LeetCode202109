#include <Solution.h>
#include <iostream>
#include <algorithm>
#include <climits>

using std::min;

int minDepth2(TreeNode* root) {
	if (!root) return 0;
	if (!root->left && !root->right) return 1;
	int left = root->left ? minDepth2(root->left) : INT_MAX;
	int right = root->right ? minDepth2(root->right) : INT_MAX;
	return min(left, right) + 1;
}
