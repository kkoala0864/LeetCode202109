#include <Solution.h>
#include <iostream>

bool Solution::validTree3(int n, vector<vector<int>>& edges) {
	vector<int> graph(n, 0);
	for (int i = 0 ; i < n ; ++i) graph[i] = i;

	for (const auto& edge : edges) {
		int s = edge[0];
		int t = edge[1];
		while (graph[s] != s) s = graph[s];
		while (graph[t] != t) t = graph[t];
		if (s == t) return false;
		graph[s] = t;
	}
	return true;
}

