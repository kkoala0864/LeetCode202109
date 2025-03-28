#include <Solution.h>
#include <iostream>
#include <unordered_map>
#include <set>

using std::set;
using std::unordered_map;

vector<vector<int>> Solution::findWinners(vector<vector<int>> &matches) {
	unordered_map<int, int> lose;
	set<int> man;
	for (const auto &m : matches) {
		man.emplace(m[0]);
		man.emplace(m[1]);
		++lose[m[1]];
	}

	vector<vector<int>> result(2);

	for (const auto &m : man) {
		if (lose.count(m) == 0) {
			result[0].emplace_back(m);
		} else if (lose[m] == 1) {
			result[1].emplace_back(m);
		}
	}
	return result;
}
