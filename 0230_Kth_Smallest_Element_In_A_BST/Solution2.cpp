#include <Solution.h>
#include <iostream>

void traverse(TreeNode* node, int& k, int& result) {
	if (k <= 0 || !node) return;

	traverse(node->left, k, result);
	if (k <= 0) return;
	--k;
	if (k == 0) result = node->val;
	traverse(node->right, k, result);
}

int Solution::kthSmallest2(TreeNode* root, int k) {
	int result = 0;
	traverse(root, k, result);
	return result;
}
