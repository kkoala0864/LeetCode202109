#include <Solution.h>
#include <iostream>
#include <unordered_map>
#include <algorithm>

using std::unordered_map;
using std::max;
using std::min;

vector<int> Solution::assignElements(vector<int>& groups, vector<int>& elements) {
	unordered_map<int, vector<int>> g;
	unordered_map<int, int> e;
	vector<int> result(groups.size(), -1);


	int mv = INT_MIN;
	for (int i = 0 ; i < groups.size() ; ++i) {
		g[groups[i]].emplace_back(i);
		mv = max(mv, groups[i]);
	}
	for (int i = 0 ; i < elements.size() ; ++i) {
		if (e.count(elements[i])) continue;
		e[elements[i]] = i;
	}

	for (const auto ev : e) {
		int ml = (mv / ev.first) + 1;
		for (int i = 1 ; i <= ml ; ++i) {
			int cur = ev.first * i;
			if (g.count(cur) == 0) continue;
			for (const auto& idx : g[cur]) {
				if (result[idx] == -1) {
					result[idx] = ev.second;
				} else {
					result[idx] = min(ev.second, result[idx]);
				}
			}
		}
	}
	return result;
}
