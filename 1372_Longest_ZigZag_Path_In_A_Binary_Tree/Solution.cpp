#include <Solution.h>
#include <iostream>
#include <algorithm>
#include <vector>

using std::vector;
using std::pair;
using std::max;

void dfs(vector<pair<int, int>>& m, TreeNode* node, int& result) {
	if (!node) return;
	node->val = m.size();
	m.emplace_back(pair<int, int>(1, 1));
	if (node->left) {
		dfs(m, node->left, result);
		m[node->val].first = max(m[node->val].first, m[node->left->val].second + 1);
	}
	if (node->right) {
		dfs(m, node->right, result);
		m[node->val].second = max(m[node->val].second, m[node->right->val].first + 1);
	}
	result = max({result, m[node->val].first, m[node->val].second});
}

int Solution::longestZigZag(TreeNode* root) {
	vector<pair<int, int>> m;
	int result = 0;

	dfs(m, root, result);
	return result - 1;
}
