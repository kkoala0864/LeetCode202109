#include <Solution.h>
#include <iostream>
#include <queue>

using std::queue;

vector<double> Solution::averageOfLevels(TreeNode* root) {
	queue<TreeNode*> que, next;

	que.emplace(root);
	vector<double> result;
	long double sum = 0;
	long double size = 1;

	while (!que.empty()) {
		auto cur = que.front();
		que.pop();

		sum += cur->val;

		if (cur->left) next.emplace(cur->left);
		if (cur->right) next.emplace(cur->right);

		if (que.empty()) {
			result.emplace_back((long double)sum / size);
			size = next.size();
			sum = 0;
			que = move(next);
		}
	}
	return result;
}
