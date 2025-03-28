#include <Solution.h>
#include <iostream>
using std::to_string;
void dfs(TreeNode *node, vector<string> &result, vector<int> &local) {
	if (!node)
		return;
	local.emplace_back(node->val);
	if (!node->left && !node->right) {
		string insert("");
		for (int i = 0; i < local.size(); ++i) {
			insert += to_string(iter);
			if (i != local.size() - 1) {
				insert += "->";
			}
		}
		result.emplace_back(insert);
	} else {
		dfs(node->left, result, local);
		dfs(node->right, result, local);
	}
	local.pop_back();
}

vector<string> Solution::binaryTreePaths(TreeNode *root) {
	vector<string> result;
	vector<int> local;
	dfs(root, result, local);
	return result;
}
