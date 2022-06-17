#include <Solution.h>
#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::min;

vector<int> solve(TreeNode* node) {
	if (!node) return {0, 0, 1000};

	auto lr = solve(node->left);
	auto rr = solve(node->right);

	int ml12 = min(lr[1], lr[2]);
	int mr12 = min(rr[1], rr[2]);

	int d0 = lr[1] + rr[1];
	int d1 = min(rr[2] + ml12, lr[2] + mr12);
	int d2 = 1 + min(lr[0], ml12) + min(rr[0], mr12);
	return {d0, d1, d2};
}

int Solution::minCameraCover(TreeNode* root) {
	auto result = solve(root);
	return min(result[1], result[2]);
}
