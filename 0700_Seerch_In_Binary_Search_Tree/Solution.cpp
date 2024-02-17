#include <Solution.h>
#include <iostream>

TreeNode* Solution::searchBST(TreeNode* root, int val) {
	if (!root) return nullptr;
	if (root->val == val) return root;
	auto left = searchBST(root->left, val);
	if (left) return left;
	return searchBST(root->right, val);
}
