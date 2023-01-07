#include "Solution.h"
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using std::unordered_map;
using std::unordered_set;
using std::queue;

void dfs2(TreeNode* node, unordered_map<TreeNode*, TreeNode*>& parent) {
	if (!node) return;

	if (node->left) {
		parent[node->left] = node;
		dfs2(node->left, parent);
	}
	if (node->right) {
		parent[node->right] = node;
		dfs2(node->right, parent);
	}
}

vector<int> Solution::distanceK2(TreeNode* root, TreeNode* target, int k) {
	unordered_map<TreeNode*, TreeNode*> parent;
	dfs2(root, parent);

	unordered_set<TreeNode*> visited;

	queue<TreeNode*> que, next;

	vector<int> result;
	que.emplace(target);
	visited.emplace(target);

	while (!que.empty()) {
		auto node = que.front();
		que.pop();

		result.emplace_back(node->val);
		if (node->left && !visited.count(node->left)) {
			visited.emplace(node->left);
			next.emplace(node->left);
		}
		if (node->right && !visited.count(node->right)) {
			visited.emplace(node->right);
			next.emplace(node->right);
		}

		if (parent[node] && !visited.count(parent[node])) {
			visited.emplace(parent[node]);
			next.emplace(parent[node]);
		}

		if (que.empty()) {
			if (k == 0) break;
			--k;
			que = move(next);
			result.clear();
		}
	}
	return result;
}
