#include <Solution.h>
#include <iostream>

void convert(TreeNode *node, int &sum) {
	if (!node)
		return;
	convert(node->right, sum);
	sum += node->val;
	node->val = sum;
	convert(node->left, sum);
}

TreeNode *Solution::convertBST(TreeNode *root) {
	if (!root)
		return root;
	int sum = 0;
	convert(root, sum);
	return root;
}
