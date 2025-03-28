#include <Solution.h>
#include <iostream>

bool Solution::hasPathSum2(TreeNode *root, int targetSum) {
	if (!root)
		return false;
	targetSum -= root->val;
	if (!root->left && !root->right)
		return targetSum == 0;
	return hasPathSum2(root->left, targetSum) || hasPathSum2(root->right, targetSum);
}
