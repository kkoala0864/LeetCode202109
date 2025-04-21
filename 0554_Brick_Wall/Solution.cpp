#include <Solution.h>
#include <iostream>
#include <unordered_map>

int Solution::leastBricks(vector<vector<int>>& wall) {

	unordered_map<long long, int> cnt;
	int maxCnt = 0;
	for (const auto& w : wall) {
		long long c = 0;
		for (int i = 0 ; i < w.size() ; ++i) {
			c += (long long)w[i];
			++cnt[c];
			if (i < w.size() - 1) {
				maxCnt = max(maxCnt, cnt[c]);
			}
		}
	}
	return wall.size() - maxCnt;
}
