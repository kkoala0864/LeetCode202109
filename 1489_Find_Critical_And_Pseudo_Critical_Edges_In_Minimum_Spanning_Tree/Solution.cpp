#include <Solution.h>
#include <iostream>
#include <algorithm>
#include <queue>

using std::min;
using std::priority_queue;

int find(vector<int> &root, int idx) {
	if (root[idx] == idx)
		return idx;
	return root[idx] = find(root, root[idx]);
}

int getMSTValue(priority_queue<vector<int>, vector<vector<int>>, std::greater<vector<int>>> pq, const vector<vector<int>> &edges, const int &n, int take, int notTake) {
	vector<int> root;
	int res = 0;
	int cnt = 0;
	for (int i = 0; i < n; ++i)
		root.emplace_back(i);

	if (take != -1) {
		root[edges[take][0]] = root[edges[take][1]] = min(edges[take][0], edges[take][1]);
		res = edges[take][2];
		++cnt;
	}

	while (cnt < (n - 1) && !pq.empty()) {
		int idx = pq.top()[1];
		int lr = find(root, edges[idx][0]);
		int rr = find(root, edges[idx][1]);
		int cost = pq.top()[0];
		pq.pop();
		if (idx == notTake)
			continue;
		if (lr == rr)
			continue;
		res += cost;
		root[lr] = root[rr] = min(lr, rr);
		++cnt;
	}
	return cnt == n - 1 ? res : INT_MAX;
}

vector<vector<int>> Solution::findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>> &edges) {
	priority_queue<vector<int>, vector<vector<int>>, std::greater<vector<int>>> pq;
	for (int i = 0; i < edges.size(); ++i) {
		pq.emplace(vector<int>({edges[i][2], i}));
	}

	int golden = getMSTValue(pq, edges, n, -1, -1);
	vector<vector<int>> result(2, vector<int>());

	for (int i = 0; i < edges.size(); ++i) {
		int v = getMSTValue(pq, edges, n, -1, i);
		if (v > golden) {
			result[0].emplace_back(i);
			continue;
		}
		v = getMSTValue(pq, edges, n, i, -1);
		if (v == golden) {
			result[1].emplace_back(i);
		}
	}
	return result;
}
