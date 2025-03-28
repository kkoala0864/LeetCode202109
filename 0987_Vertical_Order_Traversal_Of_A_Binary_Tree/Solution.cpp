#include <Solution.h>
#include <iostream>
#include <map>
#include <queue>

using std::map;
using std::pair;
using std::queue;

vector<vector<int>> Solution::verticalTraversal(TreeNode *root) {
	vector<vector<int>> result;
	if (!root)
		return result;

	map<int, vector<int>> oMap;

	queue<pair<TreeNode *, int>> que, next;
	que.emplace(pair<TreeNode *, int>(root, 0));

	map<int, vector<int>> rowMap;
	while (!que.empty()) {
		auto cur = que.front();
		que.pop();

		rowMap[cur.second].emplace_back(cur.first->val);

		if (cur.first->left)
			next.emplace(pair<TreeNode *, int>(cur.first->left, cur.second - 1));
		if (cur.first->right)
			next.emplace(pair<TreeNode *, int>(cur.first->right, cur.second + 1));

		if (que.empty()) {
			que = move(next);
			for (auto &e : rowMap) {
				sort(e.second.begin(), e.second.end(), std::greater<int>());
				while (!e.second.empty()) {
					oMap[e.first].emplace_back(e.second.back());
					e.second.pop_back();
				}
			}
		}
	}
	for (auto &e : oMap)
		result.emplace_back(e.second);
	return result;
}
