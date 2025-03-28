#include <Solution.h>
#include <iostream>
#include <queue>

using std::priority_queue;
using std::queue;

long long Solution::kthLargestLevelSum(TreeNode *root, int k) {
	priority_queue<long long> pq;

	queue<TreeNode *> que, next;
	long long sum = 0;

	que.emplace(root);
	while (!que.empty()) {
		auto cur = que.front();
		que.pop();

		sum += (long long)cur->val;
		if (cur->left)
			next.emplace(cur->left);
		if (cur->right)
			next.emplace(cur->right);

		if (que.empty()) {
			pq.emplace(sum);
			sum = 0;
			que = move(next);
		}
	}
	if (pq.size() < k)
		return -1;
	while (k-- > 1)
		pq.pop();
	return pq.top();
}
