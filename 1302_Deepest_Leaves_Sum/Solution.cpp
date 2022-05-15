#include <Solution.h>
#include <iostream>
#include <queue>

using std::queue;

void dfs(TreeNode* node, int& maxDep, int& result, int dep) {
	if (!node) return;

	if (!node->left && !node->right) {
		if (dep == maxDep) result += node->val;
		else if (dep > maxDep) {
			maxDep = dep;
			result = node->val;
		}
		return;
	}

	dfs(node->left, maxDep, result, dep+1);
	dfs(node->right, maxDep, result, dep+1);
}

int Solution::deepestLeavesSum(TreeNode* root) {
	int maxDep = 0, result = 0;
	dfs(root, maxDep, result, 1);
	return result;
}
