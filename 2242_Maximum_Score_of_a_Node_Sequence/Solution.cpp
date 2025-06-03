#include <Solution.h>
using minPQ = priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>>;

int Solution::maximumScore(vector<int>& scores, vector<vector<int>>& edges) {
	vector<minPQ> graph(scores.size(), minPQ());

	for (const auto& e : edges) {
		graph[e[0]].emplace(pair<int, int>(scores[e[1]], e[1]));
		graph[e[1]].emplace(pair<int, int>(scores[e[0]], e[0]));
		while (graph[e[0]].size() > 3) {
			graph[e[0]].pop();
		}
		while (graph[e[1]].size() > 3) {
			graph[e[1]].pop();
		}
	}

	vector<vector<pair<int, int>>> g(scores.size(), vector<pair<int, int>>());
	for (int i = 0 ; i < scores.size() ; ++i) {
		while (!graph[i].empty()) {
			g[i].emplace_back(graph[i].top());
			graph[i].pop();
		}
	}
	int result = -1;
	for (const auto& e : edges) {
		int local = 0;
		for (const auto& l : g[e[0]]) {
			if (l.second == e[0] || l.second == e[1]) continue;
			for (const auto& r : g[e[1]]) {
				if (r.second == e[0] || r.second == e[1]) continue;
				if (l.second == r.second) continue;
				local = max(local, l.first + r.first);
			}
		}
		if (local != 0) {
			result = max(result, local + scores[e[0]] + scores[e[1]]);
		}
	}
	return result;
}

