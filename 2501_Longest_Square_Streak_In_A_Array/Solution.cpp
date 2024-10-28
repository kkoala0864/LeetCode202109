#include <Solution.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using std::vector;
using std::max;

int Solution::longestSquareStreak(vector<int>& nums) {
	int maxV = 0;
	for (const auto& v : nums) maxV = max(maxV, v);
	vector<bool> us(maxV + 1, false);
	for (const auto& v : nums) us[v] = true;

	int result = -1;
	for (int i = 2 ; i <= sqrt(maxV) ; ++i) {
		if (!us[i]) continue;
		int cnt = 0;
		long long idx = i;
		while (idx <= (long long)maxV && us[idx]) {
			++cnt;
			us[idx] = false;
			idx *= idx;
		}
		if (cnt > 1) result = max(result, cnt);
	}
	return result;
}
