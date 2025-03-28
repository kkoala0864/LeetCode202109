#include <Solution.h>
#include <iostream>
#include <algorithm>
using std::min;
using std::sort;

int Solution::twoCitySchedCost(vector<vector<int>> &costs) {
	auto cmp = [](vector<int> &lhs, vector<int> &rhs) {
		return (lhs[0] - lhs[1]) < (rhs[0] - rhs[1]);
	};
	sort(costs.begin(), costs.end(), cmp);
	int result = 0;
	int n = costs.size() / 2;
	for (int i = 0; i < costs.size(); ++i) {
		if (i < n) {
			result += costs[i][0];
		} else {
			result += costs[i][1];
		}
	}
	return result;
}
