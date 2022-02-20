#include <Solution.h>
#include <iostream>
#include <unordered_map>

using std::unordered_map;

int getGCD(int a, int b) {
	while (a != 0 && b != 0) {
		if (a >= b) a %= b;
		else b %= a;
	}
	return a == 0 ? b : a;
}

long long Solution::countPairs(vector<int>& nums, int k) {
	long long result = 0;
	unordered_map<int, int> cnt;
	int sz = nums.size();

	for (int i = 0 ; i < nums.size() ; ++i) {
		int gcd = getGCD(nums[i], k);
		int rest = k / gcd;
		if (rest == 1) result += i;
		else {
			for (const auto& iter : cnt) {
				if (iter.first % rest == 0) {
					result += iter.second;
				}
			}
		}
		++cnt[gcd];
	}
	return result;
}
