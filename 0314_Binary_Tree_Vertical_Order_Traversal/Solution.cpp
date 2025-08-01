#include <Solution.h>

vector<vector<int>> Solution::verticalOrder(TreeNode *root) {
	vector<vector<int>> result;

	map<int, vector<int>> m;

	queue<pair<int, TreeNode*>> que;

	if (!root) return result;

	que.emplace(pair<int, TreeNode*>(0, root));

	while (!que.empty()) {
		auto [offset, node] = que.front();
		que.pop();

		m[offset].emplace_back(node->val);
		if (node->left) que.emplace(pair<int, TreeNode*>(offset - 1, node->left));
		if (node->right) que.emplace(pair<int, TreeNode*>(offset + 1, node->right));
	}

	for (const auto& e : m) {
		result.emplace_back(e.second);
	}
	return result;
}
