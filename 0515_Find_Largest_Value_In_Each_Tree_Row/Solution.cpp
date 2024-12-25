#include <Solution.h>
#include <iostream>
#include <queue>
#include <algorithm>
#include <climits>

using std::queue;
using std::max;

vector<int> Solution::largestValues(TreeNode* root) {
	vector<int> result;
	if (!root) return result;

	queue<TreeNode*> que, next;

	que.emplace(root);
	int v = INT_MIN;

	while (!que.empty()) {
		auto cur = que.front();
		que.pop();
		v = max(v, cur->val);

		if (cur->left) next.emplace(cur->left);
		if (cur->right) next.emplace(cur->right);

		if (que.empty()) {
			result.emplace_back(v);
			v = INT_MIN;
			que = move(next);
		}
	}
	return result;
}
