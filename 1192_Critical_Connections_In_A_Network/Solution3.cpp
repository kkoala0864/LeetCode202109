#include <Solution.h>
#include <iostream>
#include <climits>
#include <algorithm>

using std::min;

void dfs(vector<vector<int>>& connect, int curNode, int parent, int& cnt, vector<int>& minVal, vector<int>& initVal, vector<vector<int>>& result) {
	initVal[curNode] = minVal[curNode] = cnt++;

	for (const auto& v : connect[curNode]) {
		if (v == parent) continue;
		if (initVal[v] == INT_MAX) dfs(connect, v, curNode, cnt, minVal, initVal, result);

		minVal[curNode] = min(minVal[curNode], minVal[v]);

		if (initVal[curNode] < minVal[v]) {
			result.push_back({curNode, v});
		}
	}
}

vector<vector<int>> Solution::criticalConnections3(int n, vector<vector<int>>& connections) {
	vector<vector<int>> connect(n, vector<int>());
	for (const auto& con : connections) {
		connect[con[1]].emplace_back(con[0]);
		connect[con[0]].emplace_back(con[1]);
	}

	vector<int> minVal(n, INT_MAX);
	vector<int> initVal(n, INT_MAX);
	int cnt = 0;
	vector<vector<int>> result;

	dfs(connect, 0, -1, cnt, minVal, initVal, result);
	return result;
}

