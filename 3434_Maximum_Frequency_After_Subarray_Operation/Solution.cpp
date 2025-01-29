#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::max;
using std::cout;
using std::endl;

int Solution::maxFrequency(vector<int>& nums, int k) {
	int result = 0;
	int kcnt = 0;
	vector<bool> flag(51, false);
	for (const auto& v : nums) {
		flag[v] = true;
		if (v == k) ++kcnt;
	}
	for (int i = 1 ; i <= 50 ; ++i) {
		if (!flag[i] || i == k) continue;
		int cnt = 0;
		for (const auto& v : nums) {
			cnt += (v == i) ? 1 : v == k ? -1 : 0;
			result = max(result, cnt);
			if (cnt < 0) cnt = 0;
		}
	}
	return result + kcnt;
}
