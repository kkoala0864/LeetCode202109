#include <Solution.h>

int dfs(TreeNode* node, priority_queue<int>& pq) {
	if (!node) return 0;

	int lv = dfs(node->left, pq);
	int rv = dfs(node->right, pq);
	if (lv == -1 || rv == -1) return -1;

	if (lv != rv) return -1;
	int v = 1 + lv + rv;
	pq.emplace(v);
	return v;
}

int Solution::kthLargestPerfectSubtree(TreeNode* root, int k) {
	priority_queue<int> pq;
	dfs(root, pq);
	if (pq.size() < k) return -1;
	while (--k > 0) {
		pq.pop();
	}
	return pq.top();
}
