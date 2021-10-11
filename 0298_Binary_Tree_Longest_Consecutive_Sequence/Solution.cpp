#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::max;

void DFS(TreeNode* node, int cnt, int& MaxVal) {
	if (!node) {
		MaxVal = max(cnt, MaxVal);
		return;
	}

	if (node->left && node->left->val - node->val == 1) {
		DFS(node->left, cnt + 1, MaxVal);
	} else {
		MaxVal = max(cnt, MaxVal);
		DFS(node->left, 1, MaxVal);
	}

	if (node->right && node->right->val - node->val == 1) {
		DFS(node->right, cnt + 1, MaxVal);
	} else {
		MaxVal = max(cnt, MaxVal);
		DFS(node->right, 1, MaxVal);
	}
}

int Solution::longestConsecutive(TreeNode* root) {
	int MaxVal = 0;
	DFS(root, 1, MaxVal);
	return MaxVal;
}
