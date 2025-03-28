#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::max;

void dfs(TreeNode *node, int &child, int &prev) {
	if (!node)
		return;

	if (!node->left && !node->right) {
		child = node->val;
		return;
	}

	int lchild = 0, rchild = 0, lprev = 0, rprev = 0;

	dfs(node->left, lchild, lprev);
	dfs(node->right, rchild, rprev);

	child = max(node->val + lprev + rprev, lchild + rchild);
	prev = lchild + rchild;
}

int Solution::rob2(TreeNode *root) {
	int child = 0, prev = 0;

	dfs(root, child, prev);

	return child;
}
