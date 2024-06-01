#include <Solution.h>
#include <iostream>

vector<int> Solution::longestCommonSubsequence(vector<vector<int>>& arrays) {
	vector<int> cnt(101, 0);
	for (const auto& a : arrays) {
		for (const auto& v : a) {
			++cnt[v];
		}
	}
	vector<int> result;
	for (int i = 0 ; i <= 100 ; ++i) {
		if (cnt[i] == arrays.size()) {
			result.emplace_back(i);
		}
	}
	return result;
}
