#include <Solution.h>
#include <iostream>
#include <unordered_map>
#include <algorithm>

using std::max;
using std::unordered_map;

int getDep(TreeNode* node, unordered_map<int, int>& dm) {
	if (!node) return -1;
	if (dm.count(node->val)) return dm[node->val];
	dm[node->val] = max(getDep(node->left, dm), getDep(node->right, dm)) + 1;
	return dm[node->val];
}

void dfs(TreeNode* node, int dep, int maxVal, unordered_map<int, int>& dm, unordered_map<int, int>& qm) {
	if (!node) return;
	qm[node->val] = maxVal;
	dfs(node->left, dep + 1, max(maxVal, dep + 1 + getDep(node->right, dm)), dm, qm);
	dfs(node->right, dep + 1, max(maxVal, dep + 1 + getDep(node->left, dm)), dm, qm);
}

vector<int> Solution::treeQueries(TreeNode* root, vector<int>& queries) {
	unordered_map<int, int> dm;
	unordered_map<int, int> qm;
	getDep(root, dm);
	dfs(root, 0, 0, dm, qm);
	vector<int> result;

	for (const auto& q : queries) {
		result.emplace_back(qm[q]);
	}
	return result;
}
