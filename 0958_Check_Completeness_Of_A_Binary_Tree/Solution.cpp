#include <Solution.h>
#include <iostream>
#include <queue>

using std::queue;
using std::pair;

bool Solution::isCompleteTree(TreeNode* root) {
	int idx = 1;
	queue<pair<TreeNode*, int>> que;
	que.emplace(pair<TreeNode*, int>(root, 1));

	while (!que.empty()) {
		TreeNode* node = que.front().first;
		int val = que.front().second;
		que.pop();

		if (node->left) {
			if (idx != (2 * val - 1)) return false;
			que.emplace(pair<TreeNode*, int>(node->left, 2 * val));
			idx = 2 * val;
		}
		if (node->right) {
			if (idx != (2 * val)) return false;
			que.emplace(pair<TreeNode*, int>(node->right, 2 * val + 1));
			idx = 2 * val + 1;
		}
	}
	return true;
}
