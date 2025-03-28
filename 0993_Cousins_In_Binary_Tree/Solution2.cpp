#include <Solution.h>
#include <iostream>
#include <queue>

using std::queue;

bool Solution::isCousins2(TreeNode *root, int x, int y) {
	if (!root || x == y)
		return false;

	queue<TreeNode *> que, next;
	que.emplace(root);
	bool xFind = false;
	bool yFind = false;
	while (!que.empty()) {
		TreeNode *node = que.front();
		que.pop();
		if (node->left && node->right && ((node->left->val == x && node->right->val == y) || (node->left->val == y && node->right->val == x)))
			return false;

		if (node->val == x)
			xFind = true;
		if (node->val == y)
			yFind = true;
		if (node->left)
			next.emplace(node->left);
		if (node->right)
			next.emplace(node->right);

		if (que.empty()) {
			if (xFind && yFind)
				return true;
			if (xFind || yFind)
				return false;
			que = move(next);
		}
	}
	return false;
}
