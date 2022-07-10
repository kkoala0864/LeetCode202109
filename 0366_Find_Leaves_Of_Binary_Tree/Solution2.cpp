#include <Solution.h>
#include <iostream>
#include <unordered_map>
#include <queue>

using std::unordered_map;
using std::queue;

void dfs(TreeNode* cur, unordered_map<TreeNode*, int>& outdegree, unordered_map<TreeNode*, vector<TreeNode*>>& parent, queue<TreeNode*>& que) {
	if (!cur) return;

	if (cur->left) {
		++outdegree[cur];
		parent[cur->left].emplace_back(cur);
		dfs(cur->left, outdegree, parent, que);
	}
	if (cur->right) {
		++outdegree[cur];
		parent[cur->right].emplace_back(cur);
		dfs(cur->right, outdegree, parent, que);
	}
	if (outdegree[cur] == 0) que.emplace(cur);
}

vector<vector<int>> Solution::findLeaves2(TreeNode* root) {
	unordered_map<TreeNode*, int> outdegree;
	unordered_map<TreeNode*, vector<TreeNode*>> parent;
	queue<TreeNode*> que, next;

	dfs(root, outdegree, parent, que);

	vector<vector<int>> result;
	vector<int> local;
	while (!que.empty()) {
		TreeNode* cur = que.front(); que.pop();

		local.emplace_back(cur->val);

		for (const auto& ele : parent[cur]) {
			--outdegree[ele];
			if (outdegree[ele] == 0) next.emplace(ele);
		}

		if (que.empty()) {
			result.emplace_back(local);
			local.clear();
			que = move(next);
		}
	}
	return result;
}
