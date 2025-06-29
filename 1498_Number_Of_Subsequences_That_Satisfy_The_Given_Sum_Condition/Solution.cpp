#include <Solution.h>

long long quickPow(long long x, long long n, long long mod) {
	if (n == 0) return 1;
	long long v = quickPow(x, n / 2, mod);
	long long vv = v * v % mod;
	return n & 1 ? vv * x % mod : vv;
}

// fix left bound i
// 3 5 6 7 target = 9;
// i == 0
// right bound is 2 (6)
// so 3 with [5, 6] all possible => 2 ^ (len - 1) => 2 ^ ((2 - 0 + 1) - 1) = 2 ^ 2 = 4
int Solution::numSubseq(vector<int> &nums, int target) {
	sort(nums.begin(), nums.end());

	int result = 0;
	long long mod = 1e9 + 7;
	for (int l = 0 ; l < nums.size() ; ++l) {
		if (nums[l] > target) break;
		int v = target - nums[l];
		int idx = upper_bound(nums.begin() + l, nums.end(), v) - nums.begin();
		if (idx == l) continue;
		result += quickPow(2, idx - l - 1, mod);
		result %= mod;
	}
	return result;
}
