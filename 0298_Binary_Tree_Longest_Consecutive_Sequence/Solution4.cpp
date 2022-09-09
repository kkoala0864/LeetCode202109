#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::max;


void dfs4(TreeNode* node, int cnt, int& result) {
	if (!node) return;
	result = max(result, cnt);

	if (node->left) {
		dfs4(node->left, node->left->val - node->val == 1 ? cnt + 1 : 1, result);
	}
	if (node->right) {
		dfs4(node->right, node->right->val - node->val == 1 ? cnt + 1 : 1, result);
	}
}


int Solution::longestConsecutive4(TreeNode* root) {
	int result = 0;
	dfs4(root, 1, result);
	return result;
}
