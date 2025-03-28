#include <Solution.h>
#include <iostream>
#include <vector>
using std::vector;

void dfs(TreeNode *node, int target, vector<vector<int>> &result, vector<int> &local) {
	if (!node)
		return;

	local.emplace_back(node->val);
	if (!node->left && !node->right && node->val == target) {
		result.emplace_back(local);
	} else {
		dfs(node->left, target - node->val, result, local);
		dfs(node->right, target - node->val, result, local);
	}
	local.pop_back();
}

vector<vector<int>> Solution::pathSum2(TreeNode *root, int targetSum) {
	vector<vector<int>> result;
	vector<int> local;
	dfs(root, targetSum, result, local);
	return result;
}
