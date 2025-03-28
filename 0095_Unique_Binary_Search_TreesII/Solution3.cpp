#include <Solution.h>
#include <iostream>

vector<TreeNode *> dfs3(int s, int e, vector<vector<vector<TreeNode *>>> &dp) {
	if (s > e)
		return vector<TreeNode *>(1, nullptr);

	if (dp[s][e].size() > 0)
		return dp[s][e];

	for (int i = s; i <= e; ++i) {
		auto lhs = dfs3(s, i - 1, dp);
		auto rhs = dfs3(i + 1, e, dp);

		for (const auto &l : lhs) {
			for (const auto &r : rhs) {
				TreeNode *node = new TreeNode(i);
				node->left = l;
				node->right = r;
				dp[s][e].emplace_back(node);
			}
		}
	}
	return dp[s][e];
}

vector<TreeNode *> Solution::generateTrees3(int n) {
	vector<vector<vector<TreeNode *>>> dp(n + 1, vector<vector<TreeNode *>>(n + 1, vector<TreeNode *>()));
	return dfs3(1, n, dp);
}
