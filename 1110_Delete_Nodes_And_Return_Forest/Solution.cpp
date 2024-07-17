#include <Solution.h>
#include <iostream>
#include <unordered_set>

using std::unordered_set;

void recur(TreeNode* node, unordered_set<int>& delSet, vector<TreeNode*>& result) {
	if (!node) return;

	recur(node->left, delSet, result);
	recur(node->right, delSet, result);

	if (delSet.count(node->val)) {
		if (node->left && delSet.count(node->left->val) == 0) result.emplace_back(node->left);
		if (node->right && delSet.count(node->right->val) == 0) result.emplace_back(node->right);
		node->left = nullptr;
		node->right = nullptr;
	} else {
		if (node->left && delSet.count(node->left->val)) {
			node->left = nullptr;
		}
		if (node->right && delSet.count(node->right->val)) {
			node->right = nullptr;
		}
	}
}

vector<TreeNode*> Solution::delNodes(TreeNode* root, vector<int>& to_delete) {
	vector<TreeNode*> result;
	unordered_set<int> delSet;

	for (const auto& v : to_delete) delSet.emplace(v);
	recur(root, delSet, result);
	if (delSet.count(root->val) == 0) {
		result.emplace_back(root);
	}
	return result;
}
