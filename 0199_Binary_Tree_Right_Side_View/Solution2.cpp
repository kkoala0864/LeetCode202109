#include <Solution.h>
#include <iostream>
#include <queue>

using std::queue;

vector<int> Solution::rightSideView2(TreeNode* root) {
	vector<int> result;
	if (!root) return result;
	queue<TreeNode*> que, next;

	que.emplace(root);
	while (!que.empty()) {
		TreeNode* node = que.front();
		que.pop();

		if (node->left) next.emplace(node->left);
		if (node->right) next.emplace(node->right);

		if (que.empty()) {
			result.emplace_back(node->val);
			que = move(next);
		}
	}
	return result;
}
