#include <Solution.h>
#include <iostream>
#include <map>
#include <set>

using std::cout;
using std::endl;
using std::map;
using std::multiset;
using std::pair;
using std::set;

vector<vector<int>> Solution::getSkyline(vector<vector<int>> &buildings) {
	map<int, vector<pair<int, int>>> m;

	for (const auto &b : buildings) {
		m[b[0]].emplace_back(pair<int, int>(b[2], 1));
		m[b[1]].emplace_back(pair<int, int>(b[2], -1));
	}

	multiset<int> ms;
	vector<vector<int>> result;
	for (const auto &e : m) {
		for (const auto &iter : e.second) {
			if (iter.second == 1) {
				ms.emplace(iter.first);
			} else {
				ms.erase(ms.find(iter.first));
			}
		}
		int maxH = ms.empty() ? 0 : *(ms.rbegin());

		if (result.empty() || result.back()[1] != maxH) {
			result.emplace_back(vector<int>({e.first, maxH}));
		}
	}
	return result;
}
