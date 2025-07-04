#include <Solution.h>

// alice must lose =>
//
// x1 : x2^x3^x4^....^Xn = 0
// x2 : x1^x3^x4^x5....^xn = 0
// x3 : x1^x2^x4^x5....^xn = 0
// x4 : x1^x2^x3^x5....^xn = 0
// ....
// xn : x1^x2^x3^x5....^xn-1 = 0
// x1 ^ (n-1) ^ x2 ^ (n-1) ... xn ^(n-1) = 0 ^ n
// (x1 ^ x2 ...xn) ^ (n-1) = 0
// if (x1 ... xn) xor n-1 times = 0
// than n-1 must be even number
// than n must be odd number
//
// alice lose => n : odd number
// n : even number => alice win

bool Solution::xorGame(vector<int>& nums) {

	int result = 0;
	for (const auto& v : nums) {
		result ^= v;
	}
	if (result == 0) return true;
	return (nums.size() & 1) == 0;

}
