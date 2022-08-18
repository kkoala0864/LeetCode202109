#include <Solution.h>
#include <iostream>
#include <algorithm>
#include <unordered_set>

using std::max;
using std::min;
using std::unordered_set;

int Solution::maximalNetworkRank(int n, vector<vector<int>>& roads) {
	vector<unordered_set<int>> out(n, unordered_set<int>());

	for (const auto& r : roads) {
		out[r[0]].emplace(r[1]);
		out[r[1]].emplace(r[0]);
	}

	int result = 0;
	for (int i = 0 ; i < n ; ++i) {
		for (int j = 0 ; j < n ; ++j) {
			if (i == j) continue;
			int local = out[i].size() + out[j].size();
			if (out[i].find(j) != out[i].end()) --local;
			result = max(result, local);
		}
	}
	return result;
}
