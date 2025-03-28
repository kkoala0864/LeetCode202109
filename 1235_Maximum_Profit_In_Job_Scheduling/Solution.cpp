#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::max;

int findMaxProfit(vector<int> &startTime, vector<vector<int>> &jobs, vector<int> &memo) {
	int size = startTime.size();

	for (int i = size - 1; i >= 0; --i) {
		int curProfit = 0;
		int nextIdx = lower_bound(startTime.begin(), startTime.end(), jobs[i][1]) - startTime.begin();

		if (nextIdx != size) {
			curProfit = jobs[i][2] + memo[nextIdx];
		} else {
			curProfit = jobs[i][2];
		}

		if (i == size - 1) {
			memo[i] = curProfit;
		} else {
			memo[i] = max(curProfit, memo[i + 1]);
		}
	}
	return memo[0];
}

int Solution::jobScheduling(vector<int> &startTime, vector<int> &endTime, vector<int> &profit) {
	vector<vector<int>> jobs;
	vector<int> memo(50001, 0);
	for (int i = 0; i < profit.size(); ++i) {
		jobs.push_back({startTime[i], endTime[i], profit[i]});
	}

	sort(jobs.begin(), jobs.end());

	for (int i = 0; i < jobs.size(); ++i) {
		startTime[i] = jobs[i][0];
	}
	return findMaxProfit(startTime, jobs, memo);
}
