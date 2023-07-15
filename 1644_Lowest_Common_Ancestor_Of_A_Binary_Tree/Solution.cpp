#include <Solution.h>
#include <iostream>

TreeNode* dfs(TreeNode* root, TreeNode* p, TreeNode* q, bool& find) {
	if (!root) return root;
	TreeNode* left = dfs(root->left, p, q, find);
	TreeNode* right = dfs(root->right, p, q, find);

	if (left && right) {
		find = true;
		return root;
	}

	if (root == p || root == q) {
		if (left || right) find = true;
		return root;
	}

	return left ? left : right;
}

TreeNode* Solution::lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
	bool find = false;
	auto result = dfs(root, p, q, find);
	return find ? result : nullptr;
}
