#include <Solution.h>
#include <iostream>
#include <queue>
#include <vector>

using std::queue;
using std::vector;

TreeNode *Solution::replaceValueInTree(TreeNode *root) {
	vector<int> levelSum;
	queue<TreeNode *> que, next;
	vector<vector<TreeNode *>> level;
	que.emplace(root);
	int sum = 0;
	level.emplace_back(vector<TreeNode *>());

	while (!que.empty()) {
		auto cur = que.front();
		level.back().push_back(cur);
		que.pop();
		sum += cur->val;

		if (cur->left) {
			next.emplace(cur->left);
		}
		if (cur->right) {
			next.emplace(cur->right);
		}
		if (que.empty()) {
			levelSum.emplace_back(sum);
			sum = 0;
			que = move(next);
			if (!que.empty()) {
				level.push_back(vector<TreeNode *>());
			}
		}
	}

	root->val = 0;
	for (int i = 0; i < level.size() - 1; ++i) {
		for (int j = 0; j < level[i].size(); ++j) {
			int sum = levelSum[i + 1];
			if (level[i][j]->left) {
				sum -= level[i][j]->left->val;
			}
			if (level[i][j]->right) {
				sum -= level[i][j]->right->val;
			}
			if (level[i][j]->left) {
				level[i][j]->left->val = sum;
			}
			if (level[i][j]->right) {
				level[i][j]->right->val = sum;
			}
		}
	}
	return root;
}
