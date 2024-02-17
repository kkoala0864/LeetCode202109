#include <Solution.h>
#include <iostream>
using std::swap;

TreeNode* search(TreeNode* node, int key, TreeNode*& lp) {
	if (!node) return nullptr;
	if (node->val == key) return node;
	lp = node;
	if (node->val > key) {
		return search(node->left, key, lp);
	} else {
		return search(node->right, key, lp);
	}
}

TreeNode* Solution::deleteNode2(TreeNode* root, int key) {
	TreeNode* lp = nullptr;
	TreeNode* dn = search(root, key, lp);
	if (!dn) return root;

	if (!dn->left) {
		if (!lp) return dn->right;
		if (lp->left == dn) {
			lp->left = dn->right;
		} else {
			lp->right = dn->right;
		}
	} else {
		auto node = dn->left;
		auto parent = dn;
		while (node && node->right) {
			parent = node;
			node = node->right;
		}
		swap(dn->val, node->val);
		if (parent == dn) {
			parent->left = node->left;
		} else {
			parent->right = node->left;
		}
	}
	return root;
}
