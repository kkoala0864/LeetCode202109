#include <Solution.h>

int Solution::maxFreeTime(int eventTime, int k, vector<int> &startTime, vector<int> &endTime) {
	vector<int> freeTime;
	int lastEnd = 0;
	for (int i = 0 ; i < startTime.size() ; ++i) {
		freeTime.emplace_back(startTime[i] - lastEnd);
		lastEnd = endTime[i];
	}
	freeTime.emplace_back(eventTime - lastEnd);

	++k;
	int cnt = 0;
	int result = 0;
	for (int i = 0 ; i < freeTime.size() ; ++i) {
		cnt += freeTime[i];
		if (i >= k) {
			cnt -= freeTime[i-k];
		}
		if (i >= k-1) {
			result = max(result, cnt);
		}
	}
	return result;
}
