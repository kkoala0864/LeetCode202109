#include <Solution.h>
#include <iostream>
#include <queue>
#include <climits>

using std::queue;

int Solution::maxLevelSum(TreeNode* root) {
	queue<TreeNode*> que, next;

	int maxSum = INT_MIN;
	int curSum = 0;
	que.emplace(root);
	int level = 1;
	int result = 0;

	while (!que.empty()) {
		TreeNode* cur = que.front();
		que.pop();

		curSum += cur->val;

		if (cur->left) next.emplace(cur->left);
		if (cur->right) next.emplace(cur->right);
		if (que.empty()) {
			que = move(next);
			if (curSum > maxSum) {
				maxSum = curSum;
				result = level;
			}
			++level;
			curSum = 0;
		}
	}
	return result;
}
