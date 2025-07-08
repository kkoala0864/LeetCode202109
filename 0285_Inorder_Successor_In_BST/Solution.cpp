#include <Solution.h>

void dfs(TreeNode* node, TreeNode* target, TreeNode*& result) {
	if (!node) return;
	dfs(node->left, target, result);
	if (result) return;
	if (node->val > target->val) {
		result = node;
		return;
	}
	dfs(node->right, target, result);
}

TreeNode* Solution::inorderSuccessor(TreeNode *root, TreeNode *p) {
	TreeNode* result = nullptr;
	dfs(root, p, result);
	return result;
}
