#include <Solution.h>
#include <iostream>
#include <queue>
#include <unordered_map>

using std::pair;
using std::priority_queue;
using std::unordered_map;

// Bellman-Ford Algorithm
double Solution::maxProbability(int n, vector<vector<int>> &edges, vector<double> &succProb, int start_node, int end_node) {
	vector<double> maxProb(n, 0);

	maxProb[start_node] = 1.0;

	for (int i = 0; i < n - 1; ++i) {
		bool update = false;
		for (int ei = 0; ei < edges.size(); ++ei) {
			int n1 = edges[ei][0];
			int n2 = edges[ei][1];

			double prob = succProb[ei];

			if (maxProb[n1] * prob > maxProb[n2]) {
				maxProb[n2] = maxProb[n1] * prob;
				update = true;
			}
			if (maxProb[n2] * prob > maxProb[n1]) {
				maxProb[n1] = maxProb[n2] * prob;
				update = true;
			}
		}
		if (!update)
			break;
	}
	return maxProb[end_node];
}
