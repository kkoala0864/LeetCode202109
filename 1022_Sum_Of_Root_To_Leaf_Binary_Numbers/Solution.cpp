#include <Solution.h>
#include <iostream>

void traverse(TreeNode* node, int local, int& result) {
	if (!node) return;
	local = (local << 1) | node->val;
	if (!node->left && !node->right) result += local;
	traverse(node->left, local, result);
	traverse(node->right, local, result);
}

int Solution::sumRootToLeaf(TreeNode* root) {
	int result = 0;
	traverse(root, 0, result);
	return result;
}
