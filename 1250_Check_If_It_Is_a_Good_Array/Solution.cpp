#include <Solution.h>

int gcd(int x, int y) {
	if (x < y) swap(x, y);
	if (y == 0) return x;
	x %= y;
	return gcd(y, x);
}

bool Solution::isGoodArray(vector<int>& nums) {
	int v = nums[0];
	for (int i = 1 ; i < nums.size() ; ++i) {
		v = gcd(v, nums[i]);
		if (v == 1) break;
	}
	return v == 1;
}
