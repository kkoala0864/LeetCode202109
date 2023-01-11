#include <Solution.h>
#include <iostream>

void dfs(vector<vector<int>>& edge, int cur, vector<bool>& visited, vector<bool>& hasApple, int& result) {
	visited[cur] = true;
	for (const auto& n : edge[cur]) {
		if (visited[n]) continue;
		dfs(edge, n, visited, hasApple, result);
		if (hasApple[n]) {
			result += 2;
			hasApple[cur] = hasApple[cur] || hasApple[n];
		}
	}
}

int Solution::minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
	vector<vector<int>> edge(n, vector<int>());
	for (const auto& e : edges) {
		edge[e[0]].emplace_back(e[1]);
		edge[e[1]].emplace_back(e[0]);
	}
	vector<bool> visited(n, false);
	int result = 0;
	dfs(edge, 0, visited, hasApple, result);
	return result;
}
