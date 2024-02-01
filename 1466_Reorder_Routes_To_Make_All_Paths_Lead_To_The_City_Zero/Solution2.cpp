#include <Solution.h>
#include <iostream>
#include <queue>

using std::pair;
using std::queue;

int Solution::minReorder2(int n, vector<vector<int>>& connections) {
	vector<bool> visited(n, false);
	vector<vector<pair<int, int>>> out(n, vector<pair<int, int>>());

	for (const auto& c : connections) {
		out[c[0]].emplace_back(pair<int, int>(c[1], 0));
		out[c[1]].emplace_back(pair<int, int>(c[0], 1));
	}

	queue<int> que;

	int result = 0;
	que.emplace(0);
	visited[0] = true;
	while(!que.empty()) {
		int cur = que.front();
		que.pop();

		for (const auto& n : out[cur]) {
			if (visited[n.first]) continue;
			visited[n.first] = true;
			result += n.second;
			que.emplace(n.first);
		}
	}
	return n - 1 - result;
}
