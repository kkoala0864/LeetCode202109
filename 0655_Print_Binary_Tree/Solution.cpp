#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::cout;
using std::endl;
using std::max;
using std::to_string;

int getMaxD(TreeNode *node) {
	if (!node)
		return 0;
	return max(getMaxD(node->left), getMaxD(node->right)) + 1;
}

void fill(TreeNode *node, int lv, int start, int end, vector<vector<string>> &result) {
	if (!node)
		return;

	int idx = (end - start + 1) >> 1;
	idx += start;

	result[lv][idx] = to_string(node->val);

	fill(node->left, lv + 1, start, idx - 1, result);
	fill(node->right, lv + 1, idx + 1, end, result);
}

vector<vector<string>> Solution::printTree(TreeNode *root) {
	int maxDepth = getMaxD(root);
	int maxWidth = (1 << maxDepth) - 1;

	vector<vector<string>> result(maxDepth, vector<string>(maxWidth, ""));
	fill(root, 0, 0, maxWidth - 1, result);
	return result;
}
