#include <Solution.h>
#include <iostream>
using std::cout;
using std::endl;

void dfs(vector<vector<int>> &edge, int cur, vector<bool> &visited, vector<int> &cnt, const string &labels, vector<int> &result) {
	visited[cur] = true;

	for (const auto &n : edge[cur]) {
		if (visited[n])
			continue;
		vector<int> nCnt(26, 0);
		dfs(edge, n, visited, nCnt, labels, result);
		for (int i = 0; i < 26; ++i)
			cnt[i] += nCnt[i];
	}

	++cnt[labels[cur] - 'a'];
	result[cur] = cnt[labels[cur] - 'a'];
}

vector<int> Solution::countSubTrees(int n, vector<vector<int>> &edges, string labels) {
	vector<int> cnt(26, 0);
	vector<int> result(n, 0);
	vector<vector<int>> edge(n, vector<int>());
	vector<bool> visited(n, false);

	for (const auto &e : edges) {
		edge[e[0]].emplace_back(e[1]);
		edge[e[1]].emplace_back(e[0]);
	}
	dfs(edge, 0, visited, cnt, labels, result);
	return result;
}
