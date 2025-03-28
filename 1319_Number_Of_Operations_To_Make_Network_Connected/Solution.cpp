#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::min;
int find(vector<int> &g, int val) {
	if (g[val] == val)
		return val;
	return g[val] = find(g, g[val]);
}

int Solution::makeConnected(int n, vector<vector<int>> &connections) {
	vector<int> g;
	for (int i = 0; i < n; ++i)
		g.emplace_back(i);

	int same = 0;
	int groupCnt = n;
	for (int i = 0; i < connections.size(); ++i) {
		int lr = find(g, connections[i][0]);
		int rr = find(g, connections[i][1]);
		if (lr == rr) {
			++same;
			continue;
		}
		--groupCnt;
		g[lr] = g[rr] = min(lr, rr);
	}

	return groupCnt == 1 ? 0 : same >= (groupCnt - 1) ? groupCnt - 1
	                                                  : -1;
}
