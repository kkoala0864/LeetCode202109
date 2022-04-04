#include <Solution.h>
#include <iostream>

int Solution::maximumCandies(vector<int>& candies, long long k) {
	int start = 0, end = 10000000;
	int mid = 0;
	while (start < end) {
		int mid = (end + start+1) / 2;
		long long cnt = 0;
		for (const auto& iter : candies) {
			cnt += iter/mid;
		}
		if (cnt < k) {
			end = mid - 1;
		} else {
			start = mid;
		}
	}
	return start;
}
