#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int Solution::minKBitFlips(vector<int>& nums, int k) {
	int result = 0;
	int curSum = 0;

	vector<int> f(nums.size(), 0);
	int gf = 0;
	for (int i = 0 ; i < nums.size(); ++i) {
		curSum += nums[i];
		f[i] = gf;

		int lIdx = i - k;
		if (i >= k) curSum -= 1;
		if (i >= (k-1)) {
			if (((nums[lIdx+1] + gf + f[lIdx+1]) & 1) == 0) {
				gf = gf == 0 ? 1 : 0;
				++result;
				curSum = k - curSum;
			}
		}
	}
	return curSum == k ? result : -1;
}
