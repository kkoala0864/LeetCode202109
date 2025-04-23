#include <Solution.h>
#include <iostream>
#include <vector>
#include <unordered_map>

int Solution::numberOfPatterns(int m, int n) {
	vector<unordered_map<int, int>> el({
			{},
			{{3, 2}, {7, 4}, {9, 5}},
			{{8, 5}},
			{{1, 2}, {7, 5}, {9, 6}},
			{{6, 5}},
			{},
			{{4, 5}},
			{{1, 4}, {3, 5}, {9, 8}},
			{{2, 5}},
			{{1, 5}, {3, 6}, {7, 8}}
			});

	vector<unordered_map<int, int>> dp(10, unordered_map<int, int>());
	int result = 0;
	for (int i = 1 ; i <= 9 ; ++i) {
		dp[i][1 << i] = 1;
		if (m == 1) result += dp[i][1 << i];
	}

	for (int i = 1 ; i < n ; ++i) {
		vector<unordered_map<int, int>> next(10, unordered_map<int, int>());
		for (int j = 1 ; j <= 9 ; ++j) {
			for (const auto& e : dp[j]) {
				for (int k = 1 ; k <= 9 ; ++k) {
					if (e.first & (1 << k)) continue;
					if (el[j].count(k) && (e.first & (1 << el[j][k])) == 0) continue;
					next[k][e.first | (1 << k)] += e.second;
					if (i >= (m-1)) result += e.second;
				}
			}
		}
		dp = move(next);
	}
	return result;
}
