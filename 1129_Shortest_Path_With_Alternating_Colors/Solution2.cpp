#include <Solution.h>
#include <iostream>
#include <queue>
#include <algorithm>
#include <climits>

using std::cout;
using std::endl;
using std::min;
using std::pair;
using std::queue;

vector<int> Solution::shortestAlternatingPaths2(int n, vector<vector<int>> &redEdges, vector<vector<int>> &blueEdges) {
	vector<vector<int>> RE(n, vector<int>()), BE(n, vector<int>());
	;
	for (const auto &r : redEdges)
		RE[r[0]].emplace_back(r[1]);
	for (const auto &b : blueEdges)
		BE[b[0]].emplace_back(b[1]);
	vector<int> RD(n, INT_MAX);
	vector<int> BD(n, INT_MAX);

	queue<pair<int, int>> que;
	RD[0] = 0;
	BD[0] = 0;
	que.push({0, 0});
	que.push({1, 0});
	while (!que.empty()) {
		auto cur = que.front();
		que.pop();

		if (cur.first == 0) {
			for (const auto &e : BE[cur.second]) {
				if (BD[e] > RD[cur.second] + 1) {
					BD[e] = RD[cur.second] + 1;
					que.push({1, e});
				}
			}
		} else {
			for (const auto &e : RE[cur.second]) {
				if (RD[e] > BD[cur.second] + 1) {
					RD[e] = BD[cur.second] + 1;
					que.push({0, e});
				}
			}
		}
	}
	vector<int> result;
	for (int i = 0; i < n; ++i) {
		int val = min(BD[i], RD[i]);
		result.emplace_back(val == INT_MAX ? -1 : val);
	}
	return result;
}
