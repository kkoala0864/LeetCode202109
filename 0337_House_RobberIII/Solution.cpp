#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::max;

void robTree(TreeNode* node, int& prev, int& cur) {
	if (!node) return;
	if (!node->left && !node->right) {
		cur = node->val;
		return;
	}

	int lprev = 0, lcur = 0, rprev = 0, rcur = 0;
	robTree(node->left, lprev, lcur);
	robTree(node->right, rprev, rcur);

	prev = max(lprev+rprev+node->val, lcur+rcur);
	cur = prev;
	prev = lcur+rcur;
}

int Solution::rob(TreeNode* root) {
	int prev = 0, cur = 0;
	robTree(root, prev, cur);
	return cur;
}
