#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::max;

int Solution::maxDepth2(TreeNode* root) {
	if (!root) return 0;
	return max(maxDepth2(root->left), maxDepth2(root->right)) + 1;
}
