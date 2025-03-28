#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::max;

int Solution::maxFreeTime(int eventTime, int k, vector<int> &startTime, vector<int> &endTime) {
	vector<int> free;

	int cur = 0;
	for (int i = 0; i < startTime.size(); ++i) {
		free.emplace_back(startTime[i] - cur);
		cur = endTime[i];
	}
	free.emplace_back(eventTime - cur);
	int result = 0;
	cur = 0;
	for (int i = 0; i < free.size(); ++i) {
		cur += free[i];
		if (i >= k + 1) {
			cur -= free[i - (k + 1)];
		}
		if (i >= k) {
			result = max(result, cur);
		}
	}
	return result;
}
