#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::max;
using std::sort;

int Solution::latestTimeCatchTheBus(vector<int> &buses, vector<int> &passengers, int capacity) {
	sort(buses.begin(), buses.end());
	sort(passengers.begin(), passengers.end());

	int result = -1;
	int j = 0;
	int lastPerson = 0;
	for (int i = 0; i < buses.size(); ++i) {
		int cnt = 0;
		while (j < passengers.size() && cnt < capacity && passengers[j] <= buses[i]) {
			if (j == 0) {
				result = max(result, passengers[j] - 1);
			} else if ((passengers[j] - passengers[j - 1]) > 1) {
				result = max(result, passengers[j] - 1);
			}
			lastPerson = passengers[j];
			++j;
			++cnt;
		}
		if (cnt < capacity && lastPerson < buses[i]) {
			result = max(result, buses[i]);
		}
	}
	return result;
}
