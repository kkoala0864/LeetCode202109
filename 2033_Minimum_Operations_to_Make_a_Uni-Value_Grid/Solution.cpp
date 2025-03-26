#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::sort;

int Solution::minOperations(vector<vector<int>>& grid, int x) {
	vector<int> list;
	int mod = grid[0][0] % x;
	for (const auto& iter : grid) {
		for (const auto& v : iter) {
			list.emplace_back(v);
			if (v % x != mod) return -1;
		}
	}
	sort(list.begin(), list.end());

	int mid = list[list.size()/2];
	int result = 0;
	for (const auto& v : list) {
		result += (abs(mid - v) / x);
	}
	return result;
}
