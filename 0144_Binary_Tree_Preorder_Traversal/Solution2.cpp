#include <Solution.h>
#include <iostream>
#include <stack>

using std::stack;

vector<int> Solution::preorderTraversal2(TreeNode *root) {
	vector<int> result;
	if (!root)
		return result;
	stack<TreeNode *> st;

	TreeNode *dummy = new TreeNode();
	dummy->right = root;
	st.emplace(dummy);

	while (!st.empty()) {
		TreeNode *node = st.top()->right;
		st.pop();
		while (node) {
			result.emplace_back(node->val);
			st.emplace(node);
			node = node->left;
		}
	}
	return result;
}
