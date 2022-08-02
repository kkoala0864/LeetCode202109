#include <Solution.h>
#include <iostream>
#include <unordered_map>
#include <queue>

using std::unordered_map;
using std::queue;

void dfs(TreeNode* node, unordered_map<TreeNode*, TreeNode*>& parent, unordered_map<TreeNode*, int>& outdegree, queue<TreeNode*>& que) {
	if (!node) return;
	if (node->left) {
		++outdegree[node];
		parent[node->left] = node;
		dfs(node->left, parent, outdegree, que);
	}
	if (node->right) {
		++outdegree[node];
		parent[node->right] = node;
		dfs(node->right, parent, outdegree, que);
	}
	if (outdegree[node] == 0) que.emplace(node);
}

vector<vector<int>> Solution::findLeaves3(TreeNode* root) {
	unordered_map<TreeNode*, int> outdegree;
	unordered_map<TreeNode*, TreeNode*> parent;
	queue<TreeNode*> que, next;
	dfs(root, parent, outdegree, que);

	vector<vector<int>> result;
	vector<int> local;
	while (!que.empty()) {
		TreeNode* cur = que.front();
		que.pop();
		local.emplace_back(cur->val);

		--outdegree[parent[cur]];
		if (outdegree[parent[cur]] == 0) {
			next.emplace(parent[cur]);
		}

		if (que.empty()) {
			result.emplace_back(local);
			local.clear();
			que = move(next);
		}
	}
	return result;
}
