#include <Solution.h>
#include <iostream>
#include <queue>
#include <algorithm>

using std::queue;
using std::max;
using std::pair;

int Solution::widthOfBinaryTree(TreeNode* root) {
	if (!root) return 0;

	queue<pair<TreeNode*, unsigned int>> que;
	int result = 0;

	que.push({root, 0});
	while (!que.empty()) {
		unsigned int mostFront = que.front().second;
		int curSize = que.size();
		pair<TreeNode*, unsigned int> cur;
		for (int i = 0 ; i < curSize ; ++i) {
			cur = que.front();
			que.pop();
			if (cur.first->left) {
				que.push({cur.first->left, 2 * cur.second});
			}
			if (cur.first->right) {
				que.push({cur.first->right, 2 * cur.second + 1});
			}
		}
		result = max(result, (int)(cur.second - mostFront + 1));
	}
	return result;
}
