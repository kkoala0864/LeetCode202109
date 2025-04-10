#include <Solution.h>
#include <iostream>
#include <algorithm>
#include <map>

using std::map;

vector<int> Solution::corpFlightBookings(vector<vector<int>>& bookings, int n) {
	vector<int> m(n + 1, 0);

	for (const auto& b : bookings) {
		m[b[0]-1] += b[2];
		m[b[1]] -= b[2];
	}

	vector<int> result(n, 0);
	int cur = 0;
	for (int i = 0 ; i < n ; ++i) {
		cur += m[i];
		result[i] = cur;
	}
	return result;
}
