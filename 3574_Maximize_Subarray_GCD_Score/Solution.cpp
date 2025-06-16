#include <Solution.h>

// because is double not square, so only two's factor would increase one
// so it just record minimal 2 factor cnt of subarray and cnt of minimal 2 factor of subarray
// if cnt of minimal 2 factor of subarray less and equal to k than we could get more one 2 factor => it means gcd could double (gcd * 2)
// or gcd remain

long long Solution::maxGCDScore(vector<int>& nums, int k) {
	int size = nums.size();
	long long result = 0;
	for (int i = 0 ; i < size ; ++i) {
		int g = 0;
		int min2 = INT_MAX;
		int min2Cnt = 0;
		for (int j = i ; j < size ; ++j) {
			g = gcd(g, nums[j]);

			int cnt2 = __builtin_ctzll(nums[j]);

			if (min2 > cnt2) {
				min2 = cnt2;
				min2Cnt = 1;
			} else if (min2 == cnt2) {
				++min2Cnt;
			}

			long long len = j - i + 1;
			long long v = min2Cnt <= k ? 2 * g : g;
			result = max(result, len * v);
		}
	}
	return result;
}
