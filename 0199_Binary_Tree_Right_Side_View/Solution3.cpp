#include <Solution.h>
#include <iostream>
#include <queue>

using std::queue;

vector<int> Solution::rightSideView3(TreeNode* root) {
	queue<TreeNode*> que, next;

	vector<int> result;
	int local = 0;
	if (root) que.emplace(root);

	while (!que.empty()) {
		TreeNode* cur = que.front(); que.pop();
		local = cur->val;
		if (cur->left) next.emplace(cur->left);
		if (cur->right) next.emplace(cur->right);

		if (que.empty()) {
			result.emplace_back(local);
			que = move(next);
		}
	}
	return result;
}
