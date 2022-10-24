#include <Solution.h>
#include <iostream>
#include <algorithm>
#include <queue>

using std::queue;
using std::reverse;

vector<vector<int>> Solution::zigzagLevelOrder(TreeNode* root) {
	vector<vector<int>> result;

	if (!root) return result;

	vector<int> local;

	bool isReverse = false;
	queue<TreeNode*> que, next;
	que.emplace(root);

	while (!que.empty()) {
		auto cur = que.front();
		que.pop();
		local.emplace_back(cur->val);

		if (cur->left) next.emplace(cur->left);
		if (cur->right) next.emplace(cur->right);

		if (que.empty()) {
			if (isReverse) reverse(local.begin(), local.end());
			result.emplace_back(local);
			isReverse = !isReverse;
			que = move(next);
			local.clear();
		}
	}
	return result;

}
