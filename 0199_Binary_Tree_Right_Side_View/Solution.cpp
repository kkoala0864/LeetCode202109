#include <Solution.h>
#include <iostream>
#include <queue>

using std::queue;

vector<int> Solution::rightSideView(TreeNode* root) {
	if (!root) return vector<int>();
	queue<TreeNode*> cur;
	queue<TreeNode*> next;
	vector<int> result;
	cur.emplace(root);

	while (!cur.empty()) {
		if (cur.size() == 1) {
			result.emplace_back(cur.front()->val);
		}
		TreeNode* node = cur.front();
		cur.pop();
		if (node->left) next.emplace(node->left);
		if (node->right) next.emplace(node->right);
		if (cur.empty()) {
			cur = move(next);
		}
	}

	return result;
}
