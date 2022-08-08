#include <Solution.h>
#include <iostream>
#include <map>
#include <queue>

using std::map;
using std::queue;
using std::pair;

vector<vector<int>> Solution::verticalOrder(TreeNode* root) {
	map<int, vector<int>> m;
	queue<pair<TreeNode*, int>> que;

	que.emplace(pair<TreeNode*, int>(root, 0));

	while (!que.empty()) {
		auto cur = que.front();
		que.pop();

		m[cur.second].emplace_back(cur.first->val);
		if (cur.first->left) que.emplace(pair<TreeNode*, int>(cur.first->left, cur.second-1));
		if (cur.first->right) que.emplace(pair<TreeNode*, int>(cur.first->right, cur.second+1));
	}

	vector<vector<int>> result;
	for (auto& v : m) result.emplace_back(v.second);
	return result;
}
