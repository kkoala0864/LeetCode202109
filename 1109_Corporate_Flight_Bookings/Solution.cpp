#include <Solution.h>
#include <iostream>
#include <algorithm>
#include <map>

using std::map;

vector<int> Solution::corpFlightBookings(vector<vector<int>>& bookings, int n) {
	map<int, int> m;
	for (const auto& b : bookings) {
		m[b[0]] += b[2];
		m[b[1] + 1] -= b[2];
	}

	vector<int> result(n, 0);

	int cur = 0;
	auto iter = m.begin();
	for (int i = 0 ; i < n ; ++i) {
		while (iter != m.end() && iter->first <= (i+1)) {
			cur += iter->second;
			++iter;
		}
		result[i] = cur;
	}
	return result;
}
