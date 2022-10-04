#include <Solution.h>
#include <iostream>
#include <climits>
#include <queue>
#include <algorithm>
#include <unordered_set>

using std::min;
using std::unordered_set;
using std::queue;
using std::pair;

int Solution::shortestPathLength2(vector<vector<int>>& graph) {
	const int kAns = (1 << (graph.size())) - 1;
	unordered_set<int> visited;

	queue<pair<int, int>> que;
	for (int i = 0 ; i < graph.size() ; ++i) que.push({i, 1 << i});

	int steps = 0;
	while (!que.empty()) {
		int s = que.size();
		while (s--) {
			int n = que.front().first;
			int state = que.front().second;
			que.pop();
			if (state == kAns) return steps;
			int key = (n << 16) | state;
			if (visited.find(key) != visited.end()) continue;
			visited.emplace(key);
			for (const auto& node : graph[n]) {
				que.push({node, state | (1 << node)});
			}
		}
		++steps;
	}
	return -1;
}
