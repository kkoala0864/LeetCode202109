#include <Solution.h>
#include <iostream>

int dfs(TreeNode* node, int depth, TreeNode*& result, int& maxDepth) {
	if (!node) return depth;
	int ld = dfs(node->left, depth + 1, result, maxDepth);
	int rd = dfs(node->right, depth + 1, result, maxDepth);

	int curMax = max(ld, rd);
	if (curMax > maxDepth) {
		result = node;
		maxDepth = curMax;
	} else if (curMax == maxDepth) {
		if (maxDepth == ld && maxDepth == rd) {
			result = node;
		}
	}

	return curMax;
}

TreeNode* Solution::lcaDeepestLeaves(TreeNode* root) {
	TreeNode * result = nullptr;
	int maxDepth = -1;
	dfs(root, 0, result, maxDepth);
	return result;
}
