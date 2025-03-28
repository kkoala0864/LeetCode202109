#include <Solution.h>
#include <iostream>
#include <stack>

using std::stack;
/*
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
*/
vector<int> Solution::preorderTraversal(TreeNode *root) {
	if (!root)
		return vector<int>();
	stack<TreeNode *> st;
	vector<int> result;

	st.emplace(root);
	while (!st.empty()) {
		TreeNode *cur = st.top();
		st.pop();
		result.emplace_back(cur->val);
		if (cur->right) {
			st.emplace(cur->right);
		}
		if (cur->left) {
			st.emplace(cur->left);
		}
	}
	return result;
}
