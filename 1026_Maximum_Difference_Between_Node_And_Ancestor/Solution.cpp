#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::max;
using std::min;

void findMaxDiff(TreeNode* cur, int minV, int maxV, int& result) {
	if (!cur) return;
	result = max({result, abs(minV - cur->val), abs(maxV - cur->val)});

	minV = min(minV, cur->val);
	maxV = max(maxV, cur->val);
	findMaxDiff(cur->left, minV, maxV, result);
	findMaxDiff(cur->right, minV, maxV, result);
}

int Solution::maxAncestorDiff(TreeNode* root) {
	int result = 0;
	int maxV = root->val, minV = root->val;
	findMaxDiff(root, minV, maxV, result);
	return result;
}
