#include <Solution.h>
#include <iostream>

vector<TreeNode *> dfs(int start, int end) {
	if (start > end)
		return vector<TreeNode *>(1, nullptr);

	vector<TreeNode *> result;
	if (start == end) {
		TreeNode *node = new TreeNode(start);
		result.emplace_back(node);
		return result;
	}

	for (int i = start; i <= end; ++i) {
		vector<TreeNode *> left = dfs(start, i - 1);
		vector<TreeNode *> right = dfs(i + 1, end);
		for (const auto &ls : left) {
			for (const auto &rs : right) {
				TreeNode *node = new TreeNode(i, ls, rs);
				result.emplace_back(node);
			}
		}
	}
	return result;
}

vector<TreeNode *> Solution::generateTrees(int n) {
	return dfs(1, n);
}
