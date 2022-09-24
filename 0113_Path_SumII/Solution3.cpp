#include <Solution.h>
#include <iostream>

void dfs2(TreeNode* node, int targetSum, vector<vector<int>>& result, vector<int>& local) {
	if (!node) return;
	local.emplace_back(node->val);
	targetSum -= node->val;
	if (!node->left && !node->right) {
		if (targetSum == 0) result.emplace_back(local);
	} else {
		dfs2(node->left, targetSum, result, local);
		dfs2(node->right, targetSum, result, local);
	}
	local.pop_back();
}

vector<vector<int>> Solution::pathSum3(TreeNode* root, int targetSum) {
	vector<vector<int>> result;
	vector<int> local;
	dfs2(root, targetSum, result, local);
	return result;
}
