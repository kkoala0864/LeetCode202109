#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::max;

int dfs(TreeNode *node, int &cnt, double &result) {
	if (!node)
		return 0;
	int curS = 0;
	int lc = 0;
	curS += dfs(node->left, lc, result);
	int rc = 0;
	curS += dfs(node->right, rc, result);
	curS += node->val;

	cnt = lc + rc + 1;
	result = max(result, (double)curS / (double)cnt);
	return curS;
}

double Solution::maximumAverageSubtree(TreeNode *root) {
	int sum = 0;
	double result = 0;
	int n = 0;

	dfs(root, n, result);
	return result;
}
