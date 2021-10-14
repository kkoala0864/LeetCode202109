#include <Solution.h>
#include <iostream>


void traverse(TreeNode* root, vector<int>& result) {
	if (!root) return;
	result.emplace_back(root->val);
	traverse(root->left, result);
	traverse(root->right, result);
}

vector<int> Solution::preorderTraversal(TreeNode* root) {
	vector<int> result;
	traverse(root, result);
	return result;
}
