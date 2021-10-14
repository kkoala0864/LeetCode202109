#include <Solution.h>
#include <iostream>

void traverse(TreeNode* node, int targetSum, vector<vector<int>>& result, vector<int>& cur) {
	if (!node) return;
	if (!node->left && !node->right && targetSum == node->val) {
		cur.emplace_back(node->val);
		result.emplace_back(cur);
		cur.pop_back();
		return;
	}

	cur.emplace_back(node->val);
	traverse(node->left, targetSum - node->val, result, cur);
	traverse(node->right, targetSum - node->val, result, cur);
	cur.pop_back();
}

vector<vector<int>> Solution::pathSum(TreeNode* root, int targetSum) {
	vector<vector<int>> result;
	vector<int> cur;
	traverse(root, targetSum, result, cur);
	return result;
}
