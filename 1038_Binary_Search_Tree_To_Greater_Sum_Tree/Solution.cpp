#include <Solution.h>
#include <iostream>

void convert(TreeNode* root, int& sum) {
	if (!root) return;
	convert(root->right, sum);
	sum += root->val;
	root->val = sum;
	convert(root->left, sum);
}

TreeNode* Solution::bstToGst(TreeNode* root) {
	int sum = 0;
	convert(root, sum);
	return root;
}
