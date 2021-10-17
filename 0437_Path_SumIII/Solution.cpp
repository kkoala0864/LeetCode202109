#include <Solution.h>
#include <iostream>
#include <unordered_map>
#include <vector>

using std::vector;
using std::unordered_map;

void DFS(vector<int>& elements, TreeNode* node, int pathSum, int targetSum, int& cnt) {
	if (!node) return;

	pathSum += node->val;
	elements.emplace_back(node->val);

	int localSum = 0;
	for (const auto& iter : elements) {
		localSum += iter;
		if ((pathSum - localSum) == targetSum) ++cnt;
	}

	if (pathSum == targetSum) ++cnt;
	DFS(elements, node->left, pathSum, targetSum, cnt);
	DFS(elements, node->right, pathSum,  targetSum, cnt);
	elements.pop_back();
}

void DFSUMap(unordered_map<int, int>& uMap, TreeNode* node, int pathSum, int targetSum, int& cnt) {
	if (!node) return;
	pathSum += node->val;

	if (uMap.find(pathSum - targetSum) != uMap.end()) cnt += uMap[pathSum - targetSum];

	++uMap[pathSum];
	DFSUMap(uMap, node->left, pathSum, targetSum, cnt);
	DFSUMap(uMap, node->right, pathSum,  targetSum, cnt);
	--uMap[pathSum];
}

int Solution::pathSum(TreeNode* root, int targetSum) {
	int cnt = 0;
	unordered_map<int, int> uMap;
	++uMap[0];
	DFSUMap(uMap, root, 0, targetSum, cnt);
	return cnt;
}
