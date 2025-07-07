#include <Solution.h>

int dfs(TreeNode* node, int& minv, int& maxv, int& result, bool& isBST) {
	if (!node) return 0;

	int lminv = INT_MAX;
	int lmaxv = INT_MIN;
	bool lisBST = true;
	int rminv = INT_MAX;
	int rmaxv = INT_MIN;
	bool risBST = true;

	int lv = dfs(node->left, lminv, lmaxv, result, lisBST);
	int rv = dfs(node->right, rminv, rmaxv, result, risBST);
	int v = node->val + lv + rv;
	minv = min(node->val, lminv);
	maxv = max(node->val, rmaxv);
	isBST = lisBST && risBST && (node->val > lmaxv && node->val < rminv);

	if (isBST) {
		result = max(result, v);
	}
	return v;
}

int Solution::maxSumBST(TreeNode* root) {
	int result = 0;

	int minv = INT_MAX;
	int maxv = INT_MIN;
	bool isBST = true;
	dfs(root, minv, maxv, result, isBST);
	return result;
}
