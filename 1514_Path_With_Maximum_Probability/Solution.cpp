#include <Solution.h>
#include <iostream>
#include <queue>
#include <unordered_map>

using std::priority_queue;
using std::unordered_map;
using std::pair;

double Solution::maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
	unordered_map<int, unordered_map<int, double>> prob;
	vector<vector<int>> e(n, vector<int>());
	vector<double> maxProb(n, 0);

	for (int i = 0 ; i < edges.size() ; ++i) {
		e[edges[i][0]].emplace_back(edges[i][1]);
		e[edges[i][1]].emplace_back(edges[i][0]);
		prob[edges[i][0]][edges[i][1]] = succProb[i];
		prob[edges[i][1]][edges[i][0]] = succProb[i];
	}

	priority_queue<pair<double, int>> que;
	maxProb[start_node] = 1;
	que.emplace(pair<double, int>(1, start_node));

	while (!que.empty()) {
		double curProb = que.top().first;
		int curNode = que.top().second;
		que.pop();

		if (curProb < maxProb[curNode]) continue;
		if (curNode == end_node) return curProb;

		for (const auto& n : e[curNode]) {
			double p = maxProb[curNode] * prob[curNode][n];
			if (p <= maxProb[n]) continue;
			maxProb[n] = p;
			que.emplace(pair<double, int>(p, n));
		}
	}
	return 0;
}
