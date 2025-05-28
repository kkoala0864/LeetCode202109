#include <Solution.h>

int dfs(vector<vector<int>>& edge, int last, int cur, int k) {
	if (k == 0) return 1;
	int ret = 1;
	for (const auto& e : edge[cur]) {
		if (e == last) continue;
		ret += dfs(edge, cur, e, k - 1);
	}
	return ret;
}

vector<int> Solution::maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
	vector<vector<int>> e1(edges1.size() + 1, vector<int>());
	for (const auto& e : edges1) {
		e1[e[0]].emplace_back(e[1]);
		e1[e[1]].emplace_back(e[0]);
	}

	vector<int> cnt1(e1.size(), 0);
	for (int i = 0 ; i < e1.size() ; ++i) {
		cnt1[i] = dfs(e1, -1, i, k);
	}
	if (k > 0) {
		vector<vector<int>> e2(edges2.size() + 1, vector<int>());
		for (const auto& e : edges2) {
			e2[e[0]].emplace_back(e[1]);
			e2[e[1]].emplace_back(e[0]);
		}
		int max2 = 0;
		for (int i = 0 ; i < e2.size() ; ++i) {
			max2 = max(max2, dfs(e2, -1, i, k-1));
		}
		for (int i = 0 ; i < e1.size() ; ++i) {
			cnt1[i] += max2;
		}
	}
	return cnt1;
}
