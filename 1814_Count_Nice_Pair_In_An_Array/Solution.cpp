#include <Solution.h>
#include <iostream>
#include <unordered_map>

using std::unordered_map;

int rev(int n) {
	int result = 0;
	while (n > 0) {
		result *= 10;
		result += (n % 10);
		n /= 10;
	}
	return result;
}

int Solution::countNicePairs(vector<int> &nums) {
	unordered_map<int, int> m;

	int mod = 1e9 + 7;
	int result = 0;
	for (const auto &v : nums) {
		int target = v - rev(v);
		result += m[target];
		result %= mod;
		++m[target];
	}
	return result;
}
