#include <Solution.h>
#include <iostream>
#include <unordered_map>

long long Solution::countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
	unordered_map<int, int> lenCnt;
	lenCnt[0] = 1;
	int cnt = 0;
	long long result = 0;
	for (const auto& v : nums) {
		int r = v % modulo;
		if (r == k) ++cnt;

		int target = (cnt + modulo - k) % modulo;

		result += lenCnt[target];
		++lenCnt[cnt % modulo];
	}
	return result;
}
