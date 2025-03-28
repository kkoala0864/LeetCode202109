#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

void dfs(int n, vector<vector<TreeNode *>> &dp) {
	if (!dp[n].empty())
		return;

	for (int i = 1; i < n; i += 2) {
		dfs(i, dp);
		dfs(n - i - 1, dp);

		for (const auto &l : dp[i]) {
			for (const auto &r : dp[n - i - 1]) {
				TreeNode *node = new TreeNode(0);
				node->left = l;
				node->right = r;
				dp[n].emplace_back(node);
			}
		}
	}
}

vector<TreeNode *> Solution::allPossibleFBT(int n) {
	vector<vector<TreeNode *>> dp(n + 1, vector<TreeNode *>());
	dp[1].emplace_back(new TreeNode(0));
	dfs(n, dp);
	return dp[n];
}
