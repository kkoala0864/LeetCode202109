#include <Solution.h>
#include <iostream>

using std::to_string;

void dfs(TreeNode *node, string &result) {
	if (!node)
		return;

	string val = to_string(node->val);
	result += val;
	if (!node->left && !node->right)
		return;
	result.push_back('(');
	dfs(node->left, result);
	result.push_back(')');
	if (node->right) {
		result.push_back('(');
		dfs(node->right, result);
		result.push_back(')');
	}
}

string Solution::tree2str(TreeNode *root) {
	string result;
	if (!root)
		return result;
	dfs(root, result);
	return result;
}
