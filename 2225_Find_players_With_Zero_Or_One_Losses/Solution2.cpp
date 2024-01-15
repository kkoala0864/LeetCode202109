#include <Solution.h>
#include <iostream>
#include <map>

using std::map;

vector<vector<int>> Solution::findWinners2(vector<vector<int>>& matches) {
	map<int, int> lc;
	for (const auto& m : matches) {
		if (lc.count(m[0]) == 0) lc[m[0]] = 0;
		++lc[m[1]];
	}
	vector<vector<int>> result(2, vector<int>());
	for (const auto& e : lc) {
		if (e.second < 2) {
			result[e.second].emplace_back(e.first);
		}
	}
	return result;
}
