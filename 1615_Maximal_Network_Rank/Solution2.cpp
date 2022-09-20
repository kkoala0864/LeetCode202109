#include <Solution.h>
#include <iostream>
#include <unordered_set>
#include <algorithm>

using std::unordered_set;
using std::max;

int Solution::maximalNetworkRank2(int n, vector<vector<int>>& roads) {
	vector<unordered_set<int>> od(n, unordered_set<int>());

	for (const auto& r : roads) {
		od[r[0]].emplace(r[1]);
		od[r[1]].emplace(r[0]);
	}

	int result = 0;
	for (int i = 0 ; i < n ; ++i) {
		for (int j = i + 1 ; j < n ; ++j) {
			int local = od[i].size() + od[j].size();
			if (od[i].find(j) != od[i].end()) --local;
			result = max(result, local);
		}
	}
	return result;
}
