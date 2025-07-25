#include <Solution.h>

void dfs(int cur, int parent, vector<vector<int>>& g, vector<int>& nums, vector<int>& tin, vector<int>& tout, vector<int>& subxor, int& t) {
	tin[cur] = t++;
	subxor[cur] = nums[cur];

	for (const auto& n : g[cur]) {
		if (n == parent) continue;
		dfs(n, cur, g, nums, tin, tout, subxor, t);
		subxor[cur] ^= subxor[n];
	}
	tout[cur] = t++;
}

bool isAncestor(int a, int b, vector<int>& tin, vector<int>& tout) {
	return tin[a] <= tin[b] && tout[b] <= tout[a];
}

int Solution::minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
	int n = nums.size();

	vector<vector<int>> g(n, vector<int>());
	for (const auto& e : edges) {
		g[e[0]].emplace_back(e[1]);
		g[e[1]].emplace_back(e[0]);
	}

	vector<int> tin(n, 0), tout(n, 0), subxor(n, 0);
	int t = 0;
	dfs(0, -1, g, nums, tin, tout, subxor, t);

	int result = INT_MAX;
	for (int i = 1 ; i < n ; ++i) {
		for (int j = i + 1 ; j < n ; ++j) {
			int x1, x2, x3;
			if (isAncestor(i, j, tin, tout)) {
				x1 = subxor[j];
				x2 = subxor[i] ^ subxor[j];
				x3 = subxor[0] ^ subxor[i];
			} else if (isAncestor(j, i, tin, tout)) {
				x1 = subxor[i];
				x2 = subxor[j] ^ subxor[i];
				x3 = subxor[0] ^ subxor[j];
			} else {
				x1 = subxor[i];
				x2 = subxor[j];
				x3 = subxor[0] ^ subxor[i] ^ subxor[j];
			}
			int mx = max({x1, x2, x3});
			int mn = min({x1, x2, x3});
			result = min(result, mx - mn);
			if (result == 0) return 0;
		}
	}
	return result;
}
