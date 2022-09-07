#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::max;

void dfs3(TreeNode* node, int cnt, int& result) {
	if (!node) return;
	result = max(cnt, result);
	if (node->left) {
		dfs3(node->left, node->left->val - node->val == 1 ? cnt + 1 : 1, result);
	}
	if (node->right) {
		dfs3(node->right, node->right->val - node->val == 1 ? cnt + 1 : 1, result);
	}
}

int Solution::longestConsecutive3(TreeNode* root) {
	int result = 0;
	dfs3(root, 1, result);
	return result;
}
