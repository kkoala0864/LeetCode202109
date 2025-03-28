#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::max;
using std::min;

int dfs(TreeNode *cur, int &maxV, int &minV, int &result) {
	if (!cur)
		return 0;

	int lmax = INT_MIN, lmin = INT_MAX, rmax = INT_MIN, rmin = INT_MAX;
	int lv = dfs(cur->left, lmax, lmin, result);
	int rv = dfs(cur->right, rmax, rmin, result);

	if (lv < 0 || rv < 0)
		return -1;
	if (lmax >= cur->val || rmin <= cur->val)
		return -1;

	result = max(result, lv + rv + 1);
	maxV = max({lmax, rmax, cur->val});
	minV = min({lmin, rmin, cur->val});
	return lv + rv + 1;
}

int Solution::largestBSTSubtree(TreeNode *root) {
	int maxV = INT_MIN, minV = INT_MAX;
	int result = 0;
	dfs(root, maxV, minV, result);
	return result;
}
