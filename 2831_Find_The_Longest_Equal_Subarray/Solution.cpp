#include <Solution.h>
#include <iostream>
#include <unordered_map>
#include <map>
#include <algorithm>

using std::map;
using std::max;
using std::unordered_map;

int Solution::longestEqualSubarray(vector<int> &nums, int k) {
	int iter = 0;
	unordered_map<int, int> cnt;
	map<int, int, std::greater<int>> m;
	int result = 0;

	for (int i = 0; i < nums.size(); ++i) {
		int iV = nums[i];
		++cnt[iV];
		--m[cnt[iV] - 1];
		if (m[cnt[iV] - 1] == 0)
			m.erase(cnt[iV] - 1);
		++m[cnt[iV]];

		int mv = m.begin()->first;
		while (i - iter + 1 - mv > k) {
			int tV = nums[iter];
			--cnt[tV];
			++m[cnt[tV]];
			--m[cnt[tV] + 1];
			if (m[cnt[tV] + 1] == 0)
				m.erase(cnt[tV] + 1);

			mv = m.begin()->first;
			++iter;
		}
		result = max(mv, result);
	}
	return result;
}
