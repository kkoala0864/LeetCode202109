#include <Solution.h>

int dfs(TreeNode* node, int& result, int& minValue, int& maxValue) {
	if (!node) return 0;

	int lmin = INT_MAX;
	int lmax = INT_MIN;
	int rmin = INT_MAX;
	int rmax = INT_MIN;
	int leftCnt = dfs(node->left, result, lmin, lmax);
	int rightCnt = dfs(node->right, result, rmin, rmax);
	if (leftCnt == -1) return -1;
	if (rightCnt == -1) return -1;
	if (lmax >= node->val) {
		return -1;
	}
	if (rmin <= node->val) {
		return -1;
	}
	result = max(result, leftCnt + rightCnt + 1);
	minValue = min({minValue, node->val, lmin, rmin});
	maxValue = max({maxValue, node->val, lmax, rmax});
	return leftCnt + rightCnt + 1;
}

int Solution::largestBSTSubtree(TreeNode *root) {
	if (!root) return 0;
	int result = 0;
	int minValue = INT_MIN;
	int maxValue = INT_MAX;
	dfs(root, result, root->val, root->val);
	return result;
}
