#include <Solution.h>

void post(int cur, int parent, vector<int>& cnt, vector<int>& distance, vector<vector<int>>& connect) {
	for (const auto& n : connect[cur]) {
		if (n == parent) continue;
		post(n, cur, cnt, distance, connect);

		cnt[cur] += cnt[n];
		distance[cur] += (distance[n] + cnt[n]); // child more one step to root
	}
}

void reroot(int cur, int parent, vector<int>& cnt, vector<int>& distance, vector<vector<int>>& connect) {
	for (const auto& n : connect[cur]) {
		if (n == parent) continue;
		distance[n] = distance[cur] - cnt[n] + (cnt.size() - cnt[n]);
		reroot(n, cur, cnt, distance, connect);
	}
}

// # re-root algorithm
vector<int> Solution::sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
	vector<vector<int>> connect(n, vector<int>());
	for (const auto& e : edges) {
		connect[e[0]].emplace_back(e[1]);
		connect[e[1]].emplace_back(e[0]);
	}
	vector<int> cnt(n, 1);
	vector<int> distance(n, 0);

	post(0, -1, cnt, distance, connect);
	reroot(0, -1, cnt, distance, connect);

	return distance;
}
