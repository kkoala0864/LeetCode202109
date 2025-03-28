#include <Solution.h>
#include <iostream>
#include <queue>

using std::queue;

vector<vector<int>> Solution::levelOrder3(TreeNode *root) {
	vector<vector<int>> result;
	if (!root)
		return result;
	queue<TreeNode *> que, next;
	vector<int> local;

	que.emplace(root);

	while (!que.empty()) {
		TreeNode *cur = que.front();
		que.pop();
		local.emplace_back(cur->val);
		if (cur->left)
			next.emplace(cur->left);
		if (cur->right)
			next.emplace(cur->right);

		if (que.empty()) {
			que = move(next);
			result.emplace_back(local);
			local.clear();
		}
	}
	return result;
}
