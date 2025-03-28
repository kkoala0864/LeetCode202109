#include <Solution.h>
#include <iostream>
#include <unordered_map>

using std::unordered_map;

// what's total number of nodes
// what's the range of the node's val
// what's targetSum's range
// does it contain duplicate node's val ?

void dfs(TreeNode *node, long curSum, long targetSum, unordered_map<long, int> &sumMap, int &result) {
	if (!node)
		return;
	curSum += node->val;

	if (curSum == targetSum)
		++result;

	result += sumMap[curSum - targetSum];
	++sumMap[curSum];

	dfs(node->left, curSum, targetSum, sumMap, result);
	dfs(node->right, curSum, targetSum, sumMap, result);

	--sumMap[curSum];
}

int Solution::pathSum3(TreeNode *root, int targetSum) {
	if (!root)
		return 0;
	int result = 0;
	unordered_map<long, int> sumMap;
	dfs(root, 0, targetSum, sumMap, result);
	return result;
}
