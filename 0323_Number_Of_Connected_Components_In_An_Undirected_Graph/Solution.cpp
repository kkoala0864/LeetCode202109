#include <Solution.h>
#include <iostream>
/*
void traverse(const vector<vector<int>>& graph, vector<bool>& visited, int node) {
        visited[node] = true;
        for (const auto& iter : graph[node]) {
                if (visited[iter]) continue;
                traverse(graph, visited, iter);
        }
}

int Solution::countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n, vector<int>());
        for (const auto& iter : edges) {
                graph[iter[0]].emplace_back(iter[1]);
                graph[iter[1]].emplace_back(iter[0]);
        }

        vector<bool> visited(n, false);
        int cnt = 0;

        for (int i = 0 ; i < n ; ++i) {
                if (visited[i]) continue;
                ++cnt;
                traverse(graph, visited, i);
        }
        return cnt;
}
*/
// path compression
int Solution::countComponents(int n, vector<vector<int>> &edges) {
	vector<int> path(n);
	for (int i = 0; i < n; ++i)
		path[i] = i;

	int cnt = n;
	for (const auto &iter : edges) {
		int v1 = iter[0];
		int v2 = iter[1];
		while (v1 != path[v1])
			v1 = path[v1];
		while (v2 != path[v2])
			v2 = path[v2];

		if (v1 != v2) {
			--cnt;
			path[v2] = v1;
		}
	}
	return cnt;
}
