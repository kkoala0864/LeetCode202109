#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::max;

void robb(TreeNode* node, int& child, int& grand) {
	if (!node) return;
	if (!node->left && !node->right) {
		child = node->val;
		return;
	}

	int lchild = 0, rchild = 0, lgrand = 0, rgrand = 0;
	robb(node->left, lchild, lgrand);
	robb(node->right, rchild, rgrand);

	child = max(node->val + lgrand + rgrand, lchild + rchild);
	grand = lchild + rchild;
}

int Solution::rob3(TreeNode* root) {
	int child = 0, grand = 0;
	robb(root, child, grand);
	return child;
}
