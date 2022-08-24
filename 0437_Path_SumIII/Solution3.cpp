#include <Solution.h>
#include <iostream>
#include <unordered_map>

using std::unordered_map;

void dfs(TreeNode* node, int targetSum, int sum, unordered_map<int, int>& ps, int& result) {
	if (!node) return;
	sum += node->val;

	if (ps.find(sum - targetSum) != ps.end()) {
		result += ps[sum - targetSum];
	}

	++ps[sum];
	if (node->left) dfs(node->left, targetSum, sum, ps, result);
	if (node->right) dfs(node->right, targetSum, sum, ps, result);
	--ps[sum];
}

int Solution::pathSum3(TreeNode* root, int targetSum) {
	unordered_map<int, int> ps;
	++ps[0];
	int result = 0;
	dfs(root, targetSum, 0, ps, result);
	return result;
}
