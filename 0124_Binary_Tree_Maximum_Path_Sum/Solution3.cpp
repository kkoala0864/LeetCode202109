#include <Solution.h>
#include <iostream>
#include <algorithm>
#include <climits>

using std::max;

int recur(TreeNode* node, int& result) {
	if (!node) return 0;

	int sum = node->val;
	int left = recur(node->left, result);
	int right = recur(node->right, result);
	int maxChild = max(left, right);
	result = max(result, node->val + left + right);

	if (maxChild > 0) sum += maxChild;
	result = max(result, sum);
	return sum;
}

int Solution::maxPathSum3(TreeNode* root) {
	int result = INT_MIN;
	recur(root, result);
	return result;
}
