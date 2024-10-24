#include <Solution.h>
#include <iostream>

using std::swap;

bool check(TreeNode*& lhs, TreeNode*& rhs) {
	if (!lhs && !rhs) return true;
	if (!lhs || !rhs) return false;
	return lhs->val == rhs->val;
}

bool dfs(TreeNode*& r1, TreeNode*& r2) {
	if (!r1 && !r2) return true;
	if (!check(r1, r2)) return false;

	if (!check(r1->left, r2->left)) {
		swap(r1->left, r1->right);
	}
	return dfs(r1->left, r2->left) && dfs(r1->right, r2->right);
}

bool Solution::flipEquiv(TreeNode* root1, TreeNode* root2) {
	return dfs(root1, root2);
}

