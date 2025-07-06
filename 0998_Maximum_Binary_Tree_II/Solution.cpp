#include <Solution.h>

void dfs(TreeNode* node, int val) {
	if (!node) return;

	if (node->right) {
		if (node->right->val > val) {
			dfs(node->right, val);
		} else {
			TreeNode* tn = new TreeNode(val);
			tn->left = node->right;
			node->right = tn;
		}
	} else {
		node->right = new TreeNode(val);
	}
}

TreeNode* Solution::insertIntoMaxTree(TreeNode* root, int val) {
	if (!root) return new TreeNode(val);

	if (root->val < val) {
		TreeNode* node = new TreeNode(val);
		node->left = root;
		return node;
	} else {
		dfs(root, val);
		return root;
	}
}
