#include <Solution.h>
#include <iostream>

int recur(int cur, vector<vector<int>>& od, vector<bool>& visited, int& result) {
	visited[cur] = true;

	int cnt = 0;
	int last = -1;
	bool diff = false;
	for (const auto& n : od[cur]) {
		if (visited[n]) continue;
		visited[n] = true;
		int sub = recur(n, od, visited, result);
		cnt += sub;
		if (last != -1) {
			diff = diff | (last != sub);
		}
		last = sub;
	}

	if (!diff) ++result;
	return cnt + 1;
}

int Solution::countGoodNodes(vector<vector<int>>& edges) {
	vector<vector<int>> od(edges.size() + 1, vector<int>());
	for (const auto& e : edges) {
		od[e[0]].emplace_back(e[1]);
		od[e[1]].emplace_back(e[0]);
	}

	vector<bool> visited(edges.size() + 1, false);
	int result = 0;

	recur(0, od, visited, result);
	return result;
}
