#include <Solution.h>

int find(vector<int>& root, int idx) {
	if (root[idx] == idx) return idx;
	return root[idx] = find(root, root[idx]);
}

int Solution::minimumCost(int n, vector<vector<int>> &connections) {
	auto cmp = [](const vector<int>& lhs, const vector<int>& rhs) {
		return lhs[2] < rhs[2];
	};


	sort(connections.begin(), connections.end(), cmp);
	int result = 0;

	vector<int> root;
	for (int i = 0 ; i < n ; ++i) {
		root.emplace_back(i);
	}
	for (const auto& c : connections) {
		int l = find(root, c[0] - 1);
		int r = find(root, c[1] - 1);
		if (l == r) continue;
		root[l] = root[r] = min(l, r);
		--n;

		result += c[2];
	}
	return n != 1 ? -1 : result;
}
