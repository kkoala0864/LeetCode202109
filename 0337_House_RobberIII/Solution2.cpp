#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::max;

void dfs(TreeNode* node, int& child, int& childleft, int& childright) {
	if (!node) return;

	if (!node->left && !node->right) {
		child = node->val;
		return;
	}

	int leftChildLeft = 0, leftChildRight = 0;
	int rightChildLeft = 0, rightChildRight = 0;

	dfs(node->left, childleft, leftChildLeft, leftChildRight);
	dfs(node->right, childright, rightChildLeft, rightChildRight);

	child = max(childleft + childright, node->val + leftChildLeft + leftChildRight + rightChildLeft + rightChildRight);
}

int Solution::rob2(TreeNode* root) {
	int child = 0, childLeft = 0, childRight = 0;

	dfs(root, child, childLeft, childRight);

	return max(childLeft+childRight, child);
}
