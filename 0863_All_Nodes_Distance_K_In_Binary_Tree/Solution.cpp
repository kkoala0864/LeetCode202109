#include <Solution.h>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using std::queue;
using std::unordered_map;
using std::unordered_set;

void dfs(TreeNode *node, unordered_map<int, vector<int>> &adj) {
	if (!node)
		return;
	if (node->left) {
		adj[node->val].emplace_back(node->left->val);
		adj[node->left->val].emplace_back(node->val);
		dfs(node->left, adj);
	}

	if (node->right) {
		adj[node->val].emplace_back(node->right->val);
		adj[node->right->val].emplace_back(node->val);
		dfs(node->right, adj);
	}
}

vector<int> Solution::distanceK(TreeNode *root, TreeNode *target, int k) {
	unordered_map<int, vector<int>> adj;

	dfs(root, adj);

	queue<int> que, next;
	unordered_set<int> visited;
	que.emplace(target->val);
	visited.emplace(target->val);
	vector<int> result;

	while (!que.empty()) {
		int cur = que.front();
		que.pop();

		result.emplace_back(cur);

		for (const auto &n : adj[cur]) {
			if (visited.count(n))
				continue;
			next.emplace(n);
			visited.emplace(n);
		}

		if (que.empty()) {
			--k;
			if (k < 0)
				break;
			que = move(next);
			result.clear();
		}
	}
	return result;
}
