#include <Solution.h>

void dfs(TreeNode* node, double target, priority_queue<pair<double, int>, vector<pair<double, int>>, greater<>>& pq) {
	if (!node) return;
	dfs(node->left, target, pq);
	double v = abs(target - (double) node->val);
	pq.emplace(pair<double, int>(v, node->val));
	dfs(node->right, target, pq);
}

vector<int> Solution::closestKValues(TreeNode* root, double target, int k) {
	priority_queue<pair<double, int>, vector<pair<double, int>>, greater<>> pq;
	dfs(root, target, pq);

	vector<int> result;
	while (k-- > 0) {
		result.emplace_back(pq.top().second);
		pq.pop();
	}
	return result;
}
