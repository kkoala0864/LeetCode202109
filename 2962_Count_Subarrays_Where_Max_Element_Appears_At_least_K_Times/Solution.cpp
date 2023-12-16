#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::max;

long long Solution::countSubarrays(vector<int>& nums, int k) {
	long long result = 0;
	int cnt = 0;

	int mx = INT_MIN;
	for (int i = 0 ; i < nums.size() ; ++i) {
		mx = max(mx, nums[i]);
	}
	int l = 0;
	for (int i = 0 ; i < nums.size() ; ++i) {
		if (nums[i] == mx) ++cnt;
		while (cnt >= k) {
			result += (nums.size() - i);
			if (nums[l] == mx) --cnt;
			++l;
		}
	}
	return result;
}
