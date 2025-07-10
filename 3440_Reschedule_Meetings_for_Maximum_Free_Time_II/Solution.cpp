#include <Solution.h>

int Solution::maxFreeTime(int eventTime, vector<int> &startTime, vector<int> &endTime) {
	vector<int> freeTime;
	int lastEnd = 0;

	for (int i = 0 ; i < startTime.size() ; ++i) {
		freeTime.emplace_back(startTime[i] - lastEnd);
		lastEnd = endTime[i];
	}
	freeTime.emplace_back(eventTime - lastEnd);
	vector<pair<int, int>> fl;
	for (int i = 0 ; i < freeTime.size() ; ++i) {
		fl.emplace_back(pair<int, int>(freeTime[i], i));
	}

	sort(fl.begin(), fl.end());

	int result = 0;
	for (int i = 0 ; i < freeTime.size() - 1 ; ++i) {
		int curEvent = endTime[i] - startTime[i];
		int curFree = freeTime[i] + freeTime[i+1];
		int idx = lower_bound(fl.begin(), fl.end(), pair<int, int>(curEvent, INT_MIN)) - fl.begin();
		while (idx < fl.size() && (fl[idx].second == i || fl[idx].second == (i+1))) {
			++idx;
		}
		if (idx < fl.size()) {
			curFree += curEvent;
		}
		result = max(result, curFree);
	}
	return result;
}
