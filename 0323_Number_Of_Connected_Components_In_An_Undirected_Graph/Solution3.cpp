#include <Solution.h>
#include <iostream>

int Solution::countComponents3(int n, vector<vector<int>> &edges) {
	vector<int> graph(n, 0);
	for (int i = 0; i < n; ++i)
		graph[i] = i;
	for (const auto &iter : edges) {
		int x = iter[0];
		int y = iter[1];

		while (x != graph[x])
			x = graph[x];
		while (y != graph[y])
			y = graph[y];
		if (x != y) {
			--n;
			graph[x] = y;
		}
	}
	return n;
}
