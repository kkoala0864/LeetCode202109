#include <Solution.h>
#include <iostream>
#include <unordered_map>
#include <queue>

using std::queue;
using std::unordered_map;

void dfs(TreeNode *node, unordered_map<TreeNode *, TreeNode *> &parent, queue<TreeNode *> &leaves) {
	if (!node)
		return;

	if (!node->left && !node->right) {
		leaves.emplace(node);
	} else {
		if (node->left) {
			parent[node->left] = node;
		}
		if (node->right) {
			parent[node->right] = node;
		}
	}
	dfs(node->left, parent, leaves);
	dfs(node->right, parent, leaves);
}

vector<vector<int>> Solution::findLeaves(TreeNode *root) {
	unordered_map<TreeNode *, TreeNode *> parent;
	queue<TreeNode *> leaves;

	dfs(root, parent, leaves);
	vector<vector<int>> result;
	queue<TreeNode *> next;
	vector<int> insert;
	while (!leaves.empty()) {
		TreeNode *cur = leaves.front();
		leaves.pop();
		insert.emplace_back(cur->val);
		TreeNode *pt = parent[cur];
		if (pt) {
			pt->left == cur ? pt->left = nullptr : pt->right = nullptr;
			if (!pt->left && !pt->right)
				next.emplace(pt);
		}
		if (leaves.empty()) {
			result.emplace_back(insert);
			insert.clear();
			leaves = move(next);
		}
	}
	return result;
}
