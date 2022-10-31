#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::max;

int dfs3(TreeNode* node, int& grand) {
	if (!node) return 0;

	int lgrand = 0, rgrand = 0;

	int ldp = dfs3(node->left, lgrand);
	int rdp = dfs3(node->right, rgrand);

	int dp = max(node->val + lgrand + rgrand, ldp + rdp);
	grand = ldp + rdp;

	return dp;
}

int Solution::rob4(TreeNode* root) {
	int grand = 0;

	return dfs3(root, grand);
}
