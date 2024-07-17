#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::max;

int recur(TreeNode* node, int p, int q, int& result) {
	if (!node) return 0;

	int ld = recur(node->left, p, q, result);
	int rd = recur(node->right, p, q, result);

	if (ld > 0 && rd > 0) {
		result = ld + rd;
	} else if (ld > 0 || rd > 0) {
		if (node->val == q || node->val == p) {
			result = ld > 0 ? ld : rd;
		} else {
			return max(ld, rd) + 1;
		}
	} else {
		if (node->val == q || node->val == p) {
			return 1;
		}
	}

	return 0;
}

int Solution::findDistance(TreeNode* root, int p, int q) {
	int result = 0;
	recur(root, p, q, result);
	return result;
}
