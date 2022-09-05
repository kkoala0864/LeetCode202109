#include <Solution.h>
#include <iostream>
#include <queue>

using std::queue;

vector<vector<int>> Solution::levelOrder(Node* root) {
	queue<Node*> que, next;
	vector<vector<int>> result;
	if (!root) return result;

	que.emplace(root);
	vector<int> local;
	while (!que.empty()) {
		Node* cur = que.front();
		que.pop();

		local.emplace_back(cur->val);
		for (const auto& v : cur->children) {
			next.emplace(v);
		}

		if (que.empty()) {
			result.emplace_back(local);
			local.clear();
			que = move(next);
		}
	}
	return result;
}
