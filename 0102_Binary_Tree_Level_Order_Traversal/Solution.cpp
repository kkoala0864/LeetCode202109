#include <Solution.h>
#include <iostream>
#include <queue>

using std::queue;

vector<vector<int>> Solution::levelOrder(TreeNode *root) {
	queue<TreeNode *> current;
	vector<vector<int>> result;
	queue<TreeNode *> nextRound;
	vector<int> localVal;

	current.emplace(root);
	while (!current.empty()) {
		TreeNode *node = current.front();
		current.pop();
		if (node) {
			localVal.emplace_back(node->val);
			if (node->left)
				nextRound.emplace(node->left);
			if (node->right)
				nextRound.emplace(node->right);
		}

		if (current.empty()) {
			if (!localVal.empty())
				result.emplace_back(localVal);
			nextRound.swap(current);
			localVal.clear();
		}
	}
	return result;
}
