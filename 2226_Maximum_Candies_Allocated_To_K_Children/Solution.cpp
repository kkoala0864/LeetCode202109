#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::cout;
using std::endl;
using std::max;

long long check(vector<int> &c, long long mid) {
	long long result = 0;
	for (const auto &v : c) {
		result += ((long long)v / mid);
	}
	return result;
}

int Solution::maximumCandies(vector<int> &candies, long long k) {
	long long sum = 0;
	for (const auto &c : candies)
		sum += (long long)c;

	long long l = 0, r = sum / k;
	long long mid = 0;

	while (l < r) {
		mid = r - (r - l) / 2;

		if (check(candies, mid) >= k) {
			l = mid;
		} else {
			r = mid - 1;
		}
	}
	return l;
}
