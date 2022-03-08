#include <Solution.h>
#include <iostream>
#include <unordered_map>

using std::unordered_map;

void dfs(TreeNode* node, unordered_map<int, int>& uMap, int targetSum, int pathSum, int& result) {
	if (!node) return;
	pathSum += node->val;

	if (uMap.find(pathSum - targetSum) != uMap.end()) result += uMap[pathSum - targetSum];

	++uMap[pathSum];
	dfs(node->left, uMap, targetSum, pathSum, result);
	dfs(node->right, uMap, targetSum, pathSum, result);
	--uMap[pathSum];
}

int Solution::pathSum2(TreeNode* root, int targetSum) {
	if (!root) return 0;
	unordered_map<int, int> uMap;
	int result = 0;
	++uMap[0];
	dfs(root, uMap, targetSum, 0, result);
	return result;
}
