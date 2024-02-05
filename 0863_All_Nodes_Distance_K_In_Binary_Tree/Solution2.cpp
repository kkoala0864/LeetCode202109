#include "Solution.h"
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using std::vector;
using std::unordered_set;
using std::unordered_map;

void dfs2(TreeNode* node, unordered_map<int, vector<int>>& graph) {
	if (!node) return;
	if (node->left) {
		graph[node->val].emplace_back(node->left->val);
		graph[node->left->val].emplace_back(node->val);
		dfs2(node->left, graph);
	}
	if (node->right) {
		graph[node->val].emplace_back(node->right->val);
		graph[node->right->val].emplace_back(node->val);
		dfs2(node->right, graph);
	}
}

vector<int> Solution::distanceK2(TreeNode* root, TreeNode* target, int k) {
	unordered_map<int, vector<int>> graph;

	unordered_set<int> visited;
	dfs2(root, graph);

	vector<int> que,next;
	que.emplace_back(target->val);
	visited.emplace(target->val);
	if (k == 0) return que;

	while (!que.empty()) {
		int node = que.back();
		que.pop_back();

		for (const auto& n : graph[node]) {
			if (visited.count(n)) continue;
			visited.emplace(n);
			next.emplace_back(n);
		}
		if (que.empty()) {
			--k;
			if (k == 0) return next;
			que = move(next);
		}
	}
	return vector<int>();

}
