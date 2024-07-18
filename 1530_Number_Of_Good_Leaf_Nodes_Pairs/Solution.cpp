#include <Solution.h>
#include <iostream>
#include <vector>

using std::vector;

void recur(TreeNode* node, int distance, vector<int>& dc, int& result) {
	if (!node) return;
	if (!node->left && !node->right) {
		++dc[1];
		return;
	}

	vector<int> ldc(distance + 1, 0), rdc(distance + 1, 0);
	recur(node->left, distance, ldc, result);
	recur(node->right, distance, rdc, result);

	for (int i = 1 ; i < distance ; ++i) {
		for (int j = 1 ; (i + j) <= distance ; ++j) {
			result += (ldc[i] * rdc[j]);
		}
	}
	for (int i = 0 ; i < distance ; ++i) {
		dc[i+1] += ldc[i];
		dc[i+1] += rdc[i];
	}
}


int Solution::countPairs(TreeNode* root, int distance) {
	int result = 0;
	vector<int> dc(distance + 1, 0);
	recur(root, distance, dc, result);
	return result;
}
