#include <Solution.h>
#include <iostream>
#include <climits>
/*
bool inorder(TreeNode* root, vector<int>& record) {
	if (!root) return true;
	if (!inorder(root->left, record)) return false;
	if (!record.empty() && record.back() >= root->val) return false;
	record.emplace_back(root->val);
	return inorder(root->right, record);
}

bool Solution::isValidBST(TreeNode* root) {
	vector<int> record;
	return inorder(root, record);
}
*/


bool valid(TreeNode* root, long minV, long maxV) {
	if (!root) return true;

	if ((root->val <= minV) || (root->val >= maxV)) return false;

	return valid(root->left, minV, root->val) && valid(root->right, root->val, maxV);

}

bool Solution::isValidBST(TreeNode* root) {
	return valid(root, LONG_MIN, LONG_MAX);
}

