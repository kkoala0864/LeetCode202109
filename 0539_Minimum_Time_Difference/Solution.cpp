#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::min;
using std::sort;

int Solution::findMinDifference(vector<string> &timePoints) {
	vector<int> time;

	for (const auto &t : timePoints) {
		int idx = t.find(":");
		int h = stoi(t.substr(0, idx));
		int m = stoi(t.substr(idx + 1));

		m += (h * 60);
		time.emplace_back(m);
	}

	sort(time.begin(), time.end());

	int result = INT_MAX;
	for (int i = 0; i < time.size() - 1; ++i) {
		result = min(result, time[i + 1] - time[i]);
	}

	result = min(result, time[0] + (24 * 60) - time.back());

	return result;
}
