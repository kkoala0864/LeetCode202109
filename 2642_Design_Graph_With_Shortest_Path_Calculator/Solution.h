#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using std::min;
using std::pair;
using std::queue;
using std::vector;

class Graph {
public:
	Graph(int n, vector<vector<int>> &edges) {
		g = vector<vector<int>>(n, vector<int>(n, INT_MAX));
		for (int i = 0; i < n; ++i)
			g[i][i] = 0;
		for (const auto &e : edges) {
			g[e[0]][e[1]] = e[2];
		}
	}

	void addEdge(vector<int> edge) {
		g[edge[0]][edge[1]] = min(g[edge[0]][edge[1]], edge[2]);
	}

	int shortestPath(int node1, int node2) {
		queue<pair<int, int>> que;
		for (int i = 0; i < g.size(); ++i) {
			if (g[node1][i] != INT_MAX && g[node1][i] != 0) {
				que.emplace(pair<int, int>(i, g[node1][i]));
			}
		}

		while (!que.empty()) {
			int cur = que.front().first;
			int cost = que.front().second;
			que.pop();
			if (cost > g[node1][cur])
				continue;
			for (int i = 0; i < g.size(); ++i) {
				if (g[cur][i] == INT_MAX)
					continue;
				if (g[node1][i] > (g[cur][i] + cost)) {
					g[node1][i] = g[cur][i] + cost;
					que.emplace(pair<int, int>(i, g[node1][i]));
				}
			}
		}
		return g[node1][node2] == INT_MAX ? -1 : g[node1][node2];
	}

private:
	vector<vector<int>> g;
	virtual ~Graph() {
	}
	Graph &operator=(const Graph &source);
	Graph(const Graph &);
};
