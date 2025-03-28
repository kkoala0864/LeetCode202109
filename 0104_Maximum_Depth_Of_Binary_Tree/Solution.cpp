#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::max;

int Solution::maxDepth(TreeNode *root) {
	if (!root)
		return 0;
	else
		return max(maxDepth(root->left), maxDepth(root->right)) + 1;
}
