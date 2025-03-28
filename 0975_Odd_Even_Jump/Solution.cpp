#include <Solution.h>
#include <iostream>
#include <climits>
#include <map>

using std::cout;
using std::endl;
using std::map;

int Solution::oddEvenJumps(vector<int> &arr) {
	vector<vector<int>> dp(arr.size(), vector<int>(2, 2));
	map<int, int> m;
	int result = 1;
	dp.back()[0] = 1;
	dp.back()[1] = 1;
	m[arr.back()] = arr.size() - 1;

	for (int i = arr.size() - 2; i >= 0; --i) {
		auto iter = m.lower_bound(arr[i]);
		if (iter == m.end()) {
			dp[i][0] = 0;
			--iter;
			dp[i][1] = dp[iter->second][0];
		} else {
			int nIdx = iter->second;
			dp[i][0] = dp[nIdx][1];
			if (iter->first > arr[i]) {
				if (iter == m.begin()) {
					dp[i][1] = 0;
				} else {
					--iter;
					dp[i][1] = dp[iter->second][0];
				}
			} else {
				dp[i][1] = dp[iter->second][0];
			}
		}
		if (dp[i][0])
			++result;
		m[arr[i]] = i;
	}
	return result;
}
