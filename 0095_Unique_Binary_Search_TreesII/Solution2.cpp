#include <Solution.h>
#include <iostream>

void dfs(int start, int end, vector<vector<vector<TreeNode*>>>& dp) {
	if (!dp[start][end].empty()) return;
	if (start > end) {
		dp[start][end].emplace_back(nullptr);
		return;
	}

	for (int i = start ; i <= end ; ++i) {
		dfs(start, i - 1, dp);
		dfs(i + 1, end, dp);

		for (const auto& ln : dp[start][i-1]) {
			for (const auto& rn : dp[i+1][end]) {
				TreeNode* cur = new TreeNode(i, ln, rn);
				dp[start][end].emplace_back(cur);
			}
		}
	}
}

vector<TreeNode*> Solution::generateTrees2(int n) {
	vector<vector<vector<TreeNode*>>> dp(n + 2, vector<vector<TreeNode*>>(n + 2, vector<TreeNode*>()));
	dfs(1, n, dp);
	return dp[1][n];
}
