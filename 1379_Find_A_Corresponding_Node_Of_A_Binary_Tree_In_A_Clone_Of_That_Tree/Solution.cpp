#include <Solution.h>
#include <iostream>
#include <queue>

using std::pair;
using std::queue;

TreeNode *Solution::getTargetCopy(TreeNode *original, TreeNode *cloned, TreeNode *target) {
	queue<pair<TreeNode *, TreeNode *>> que;

	que.push({original, cloned});

	while (!que.empty()) {
		auto cur = que.front();
		que.pop();
		if (cur.first == target)
			return cur.second;

		if (cur.first->left)
			que.push({cur.first->left, cur.second->left});
		if (cur.first->right)
			que.push({cur.first->right, cur.second->right});
	}
	return nullptr;
}
