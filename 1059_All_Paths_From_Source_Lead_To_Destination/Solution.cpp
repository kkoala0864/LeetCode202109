#include <Solution.h>
#include <iostream>

bool dfs(vector<vector<int>> &odg, int cur, int destination, vector<bool> &visited, vector<int> &cache) {
	if (cur == destination)
		return true;
	if (cache[cur] != 0)
		return cache[cur] == 1;
	visited[cur] = true;

	if (odg[cur].empty())
		return false;

	int cnt = odg[cur].size();
	for (const auto &node : odg[cur]) {
		if (visited[node])
			continue;
		bool result = dfs(odg, node, destination, visited, cache);
		if (result)
			--cnt;
	}

	visited[cur] = false;
	cache[cur] = cnt == 0 ? 1 : 2;
	return cnt == 0;
}

bool Solution::leadsToDestination(int n, vector<vector<int>> &edges, int source, int destination) {
	vector<vector<int>> odg(n, vector<int>());

	for (auto &e : edges)
		odg[e[0]].emplace_back(e[1]);
	if (!odg[destination].empty())
		return false;
	vector<bool> visited(n, false);
	vector<int> cache(n, 0);
	return dfs(odg, source, destination, visited, cache);
}
