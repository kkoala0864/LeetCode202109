#include <Solution.h>
#include <iostream>
#include <vector>

using std::vector;
using std::swap;

void inorder(TreeNode* node, TreeNode*& pre, vector<vector<TreeNode*>>& sVec) {
	if (!node) return;
	inorder(node->left, pre, sVec);
	if (pre && pre->val > node->val) {
		sVec.push_back({pre, node});
	}
	pre = node;
	return inorder(node->right, pre, sVec);
}

void Solution::recoverTree(TreeNode* root) {
	vector<vector<TreeNode*>> sVec;
	TreeNode* pre = nullptr;
	inorder(root, pre, sVec);
	if (sVec.size() == 1) {
		swap(sVec[0][0]->val, sVec[0][1]->val);
	} else if (sVec.size() == 2) {
		swap(sVec[0][0]->val, sVec[1][1]->val);
	}
}
