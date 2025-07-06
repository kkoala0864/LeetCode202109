#include <Solution.h>

void dfs(TreeNode* node, int x, int y, map<int, map<int, multiset<int>>>& value) {
	if (!node) return;
	value[y][x].emplace(node->val);

	dfs(node->left, x + 1, y - 1, value);
	dfs(node->right, x + 1, y + 1, value);
}

vector<vector<int>> Solution::verticalTraversal(TreeNode *root) {
	map<int, map<int, multiset<int>>> value;
	dfs(root, 0, 0, value);

	vector<vector<int>> result;
	for (const auto& sm : value) {
		vector<int> list;
		for (const auto& e : sm.second) {
			for (const auto& s : e.second) {
				list.emplace_back(s);
			}
		}
		result.emplace_back(list);
	}
	return result;
}
