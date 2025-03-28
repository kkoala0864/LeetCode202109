#include <Solution.h>
#include <iostream>

void traverse(TreeNode *node, int &k, int &result) {
	if (!node || 0 == k)
		return;
	traverse(node->left, k, result);
	if (0 == k)
		return;
	if (0 == --k)
		result = node->val;
	traverse(node->right, k, result);
}

int Solution::kthSmallest(TreeNode *root, int k) {
	int result = 0;
	traverse(root, k, result);
	return result;
}
