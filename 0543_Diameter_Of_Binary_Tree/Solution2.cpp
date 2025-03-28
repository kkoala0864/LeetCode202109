#include <Solution.h>
#include <iostream>
#include <algorithm>
#include <climits>

using std::max;

int dfs(TreeNode *node, int &result) {
	if (!node)
		return 0;

	int left = dfs(node->left, result);
	int right = dfs(node->right, result);

	result = max(result, left + right);

	return max(left, right) + 1;
}

int Solution::diameterOfBinaryTree2(TreeNode *root) {
	int result = 0;
	dfs(root, result);
	return result;
}
