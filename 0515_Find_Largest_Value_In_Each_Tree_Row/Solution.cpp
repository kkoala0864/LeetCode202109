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
	int lv = INT_MIN;

	while (!que.empty()) {
		auto cur = que.front();
		que.pop();

		lv = max(lv, cur->val);

		if (cur->left) next.emplace(cur->left);
		if (cur->right) next.emplace(cur->right);

		if (que.empty()) {
			que = move(next);
			result.emplace_back(lv);
			lv = INT_MIN;
		}
	}
	return result;
}
