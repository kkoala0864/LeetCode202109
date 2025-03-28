#include <Solution.h>
#include <iostream>
#include <unordered_map>
#include <queue>
#include <vector>
#include <unordered_set>

using std::queue;
using std::unordered_map;
using std::unordered_set;
using std::vector;

void dfs(TreeNode *node, unordered_map<int, vector<int>> &o) {
	if (!node)
		return;
	if (node->left) {
		o[node->val].emplace_back(node->left->val);
		o[node->left->val].emplace_back(node->val);
		dfs(node->left, o);
	}
	if (node->right) {
		o[node->val].emplace_back(node->right->val);
		o[node->right->val].emplace_back(node->val);
		dfs(node->right, o);
	}
}

int Solution::amountOfTime(TreeNode *root, int start) {
	unordered_map<int, vector<int>> o;
	unordered_set<int> s;

	dfs(root, o);

	queue<int> que, next;
	int result = 0;

	que.emplace(start);
	s.emplace(start);

	while (!que.empty()) {
		int cur = que.front();
		que.pop();
		for (const auto &n : o[cur]) {
			if (s.count(n) > 0)
				continue;
			s.emplace(n);
			next.emplace(n);
		}

		if (que.empty()) {
			++result;
			que = move(next);
		}
	}
	return result - 1;
}
