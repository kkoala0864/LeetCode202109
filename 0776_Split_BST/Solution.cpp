#include <Solution.h>
#include <iostream>
#include <queue>

using std::queue;

void insert(TreeNode *&node, TreeNode *&cur) {
	if (!node) {
		node = cur;
	} else if (cur->val > node->val) {
		insert(node->right, cur);
	} else {
		insert(node->left, cur);
	}
}

vector<TreeNode *> Solution::splitBST(TreeNode *root, int target) {
	vector<TreeNode *> result(2, nullptr);

	queue<TreeNode *> que;
	que.emplace(root);

	while (!que.empty()) {
		TreeNode *cur = que.front();
		que.pop();

		if (cur->left) {
			que.emplace(cur->left);
		}
		if (cur->right) {
			que.emplace(cur->right);
		}
		cur->left = nullptr;
		cur->right = nullptr;
		if (cur->val <= target) {
			insert(result[0], cur);
		} else {
			insert(result[1], cur);
		}
	}
	return result;
}
