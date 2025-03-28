#include <Solution.h>
#include <iostream>
#include <queue>

using std::queue;

vector<vector<int>> Solution::levelOrder2(TreeNode *root) {
	vector<vector<int>> result;
	if (!root)
		return result;
	queue<TreeNode *> cur, next;
	cur.emplace(root);
	vector<int> local;
	while (!cur.empty()) {
		TreeNode *node = cur.front();
		cur.pop();

		if (node->left)
			next.emplace(node->left);
		if (node->right)
			next.emplace(node->right);
		local.emplace_back(node->val);

		if (cur.empty()) {
			cur = move(next);
			result.emplace_back(local);
			local.clear();
		}
	}
	return result;
}
