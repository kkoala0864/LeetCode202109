#include <Solution.h>
#include <iostream>
#include <queue>

using std::queue;

bool Solution::isEvenOddTree(TreeNode* root) {
	if (!root) return true;

	int level = 0;
	queue<TreeNode*> que, next;
	TreeNode* lastNode = nullptr;

	que.emplace(root);
	while (!que.empty()) {
		TreeNode* cur = que.front();
		que.pop();

		if (level & 1) {
			if (cur->val & 1) return false;
			if (lastNode && lastNode->val <= cur->val) return false;
		} else {
			if ((cur->val & 1) == 0) return false;
			if (lastNode && lastNode->val >= cur->val) return false;
		}
		lastNode = cur;
		if (cur->left) next.emplace(cur->left);
		if (cur->right) next.emplace(cur->right);

		if (que.empty()) {
			que = move(next);
			++level;
			lastNode = nullptr;
		}
	}
	return true;
}
