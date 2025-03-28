#include <Solution.h>
#include <iostream>
#include <algorithm>
#include <queue>

using std::max;
using std::priority_queue;

int dfs(int cur, vector<vector<int>> &child, const string &s, int &result) {
	priority_queue<int> pq;
	int childVal = 0;
	for (const auto &n : child[cur]) {
		childVal = dfs(n, child, s, result);
		if (s[cur] != s[n])
			pq.emplace(childVal);
	}

	int local = 0;
	int ver = 1;
	if (!pq.empty())
		ver += pq.top();
	if (pq.size() > 1) {
		local += pq.top();
		pq.pop();
		local += pq.top();
		pq.pop();
		result = max(result, local + 1);
	}
	result = max(result, ver);
	return ver;
}

int Solution::longestPath(vector<int> &parent, string s) {
	if (s.empty())
		return 0;
	int result = 1;
	vector<vector<int>> child(parent.size(), vector<int>());
	for (int i = 0; i < parent.size(); ++i) {
		if (parent[i] == -1)
			continue;
		child[parent[i]].emplace_back(i);
	}
	dfs(0, child, s, result);
	return result;
}
