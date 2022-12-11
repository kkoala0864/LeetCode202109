#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::max;
void sumAll(TreeNode* node, long long& totalSum) {
	if (!node) return;
	totalSum += node->val;
	sumAll(node->left, totalSum);
	sumAll(node->right, totalSum);
}

long long dfs(TreeNode* node, long long totalSum, long long& result) {
	if (!node) return 0;

	long long lr = dfs(node->left, totalSum, result);
	long long rr = dfs(node->right, totalSum, result);

	result = max({result, (totalSum - lr) * lr, (totalSum - rr) * rr});
	return lr + rr + node->val;
}

int Solution::maxProduct(TreeNode* root) {
	long long totalSum = 0;
	sumAll(root, totalSum);
	long long result = 0;
	int mod = 1e9 + 7;
	dfs(root, totalSum, result);
	return result % mod;
}
