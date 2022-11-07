#include <Solution.h>
#include <iostream>

vector<TreeNode*> dfs(int s, int e, vector<vector<vector<TreeNode*>>>& cache) {
	if (s > e) return { nullptr };
	if (s == e) return vector<TreeNode*>(1, new TreeNode(s));

	if (!cache[s][e].empty()) return cache[s][e];

	for (int i = s ; i <= e ; ++i) {
		auto lr = dfs(s, i-1, cache);
		auto rr = dfs(i + 1, e, cache);
		for (auto& l : lr) {
			for (auto& r : rr) {
				TreeNode* node = new TreeNode(i);
				node->left = l;
				node->right = r;
				cache[s][e].emplace_back(node);
			}
		}
	}

	return cache[s][e];
}

vector<TreeNode*> Solution::generateTrees2(int n) {
	vector<vector<vector<TreeNode*>>> cache(n+1, vector<vector<TreeNode*>>(n+1, vector<TreeNode*>()));
	return dfs(1, n, cache);
}
