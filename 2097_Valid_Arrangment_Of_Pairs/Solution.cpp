#include <Solution.h>
#include <iostream>
#include <unordered_map>

using std::unordered_map;

void dfs(unordered_map<int, vector<int>> &od, int cur, vector<int> &order) {
	while (!od[cur].empty()) {
		int n = od[cur].back();
		od[cur].pop_back();
		dfs(od, n, order);
	}
	order.emplace_back(cur);
}

vector<vector<int>> Solution::validArrangement(vector<vector<int>> &pairs) {
	unordered_map<int, vector<int>> od;
	unordered_map<int, int> id;

	for (const auto &p : pairs) {
		od[p[0]].emplace_back(p[1]);
		++id[p[1]];
	}

	vector<int> order;
	vector<vector<int>> result;
	int n = pairs.size();
	for (const auto &e : od) {
		if (e.second.size() <= id[e.first])
			continue;
		dfs(od, e.first, order);
		if ((order.size() - 1) == n)
			break;
	}
	if ((order.size() - 1) != n) {
		dfs(od, od.begin()->first, order);
	}
	if ((order.size() - 1) != n)
		return result;
	reverse(order.begin(), order.end());
	for (int i = 0; i < order.size() - 1; ++i) {
		result.emplace_back(vector<int>({order[i], order[i + 1]}));
	}
	return result;
}
