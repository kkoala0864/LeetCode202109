#include <Solution.h>
#include <iostream>

int getOne(int n) {
	int result = 0;
	while (n) {
		++result;
		n &= (n - 1);
	}
	return result;
}

void dfs2(TreeNode *root, int mask, int &result) {
	if (!root)
		return;
	mask ^= (1 << root->val);
	if (!root->left && !root->right) {
		int v = getOne(mask);
		if (v == 0 || v == 1)
			++result;
		return;
	}
	dfs2(root->left, mask, result);
	dfs2(root->right, mask, result);
}

int Solution::pseudoPalindromicPaths2(TreeNode *root) {
	int result = 0;
	dfs2(root, 0, result);
	return result;
}
