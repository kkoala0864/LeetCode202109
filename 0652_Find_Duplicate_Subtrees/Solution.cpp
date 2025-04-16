#include <Solution.h>
#include <iostream>
#include <unordered_map>
#include <string>

string dfs(TreeNode* node, unordered_map<string, int>& m, vector<TreeNode*>& result) {
	if (!node) return "null,";

	string s = to_string(node->val);
	s.push_back(',');

	string ls = dfs(node->left, m, result);
	string rs = dfs(node->right, m, result);

	s += (ls + rs);
	if (m.count(s) == 0) {
		m[s] = 1;
	} else {
		++m[s];
		if (m[s] == 2) {
			result.emplace_back(node);
		}
	}
	return s;
}

vector<TreeNode*> Solution::findDuplicateSubtrees(TreeNode* root) {
	unordered_map<string, int> m;
	vector<TreeNode*> result;

	dfs(root, m, result);
	return result;
}
