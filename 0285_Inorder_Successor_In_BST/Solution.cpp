#include <Solution.h>
#include <iostream>


void dfs(TreeNode* cur, int pVal, int& minVal, TreeNode*& result) {
	if (!cur) return;

	dfs(cur->left, pVal, minVal, result);
	if (minVal != INT_MAX) return;
	if (cur->val > pVal) {
		if (cur->val < minVal) {
			minVal = cur->val;
			result = cur;
		}
	}
	if (minVal != INT_MAX) return;
	dfs(cur->right, pVal, minVal, result);
}

TreeNode* Solution::inorderSuccessor(TreeNode* root, TreeNode* p) {
	int minVal = INT_MAX;
	TreeNode* result = nullptr;
	dfs(root, p->val, minVal, result);
	return result;
}
