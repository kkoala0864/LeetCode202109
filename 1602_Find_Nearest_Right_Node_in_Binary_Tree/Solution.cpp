#include <Solution.h>

TreeNode* Solution::findNearestRightNode(TreeNode* root, TreeNode* u) {
	queue<TreeNode*> que, next;

	que.emplace(root);

	TreeNode* pre = nullptr;
	while (!que.empty()) {
		auto node = que.front();
		que.pop();

		if (pre == u) return node;
		pre = node;
		if (node->left) {
			next.emplace(node->left);
		}
		if (node->right) {
			next.emplace(node->right);
		}
		if (que.empty()) {
			if (pre == u) return nullptr;
			pre = nullptr;
			que = std::move(next);
		}
	}
	return nullptr;

}
