#include <Solution.h>
#include <iostream>
#include <climits>
#include <unordered_map>
#include <algorithm>

using std::min;
using std::unordered_map;

long long getTrips(unordered_map<long long, long long>& m, long long t) {
	long long result = 0;
	for (const auto& v : m) {
		result += (t / v.first) * v.second;
	}
	return result;
}

long long Solution::minimumTime(vector<int>& time, int totalTrips) {
	int minVal = INT_MAX;
	unordered_map<long long, long long> m;
	for (const auto& v : time) {
		minVal = min(minVal, v);
		++m[v];
	}
	long long l = 0, r = (long long)minVal * (long long)totalTrips;
	long long mid = 0;

	while (l < r) {
		mid = l + ((r - l) >> 1);

		long long trips = getTrips(m, mid);

		if (trips < (long long)totalTrips) {
			l = mid + 1;
		} else {
			r = mid;
		}
	}
	return l;
}
