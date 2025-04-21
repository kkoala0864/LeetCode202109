#include <Solution.h>
#include <iostream>
#include <queue>

// insert server weight with server indx and time vector<int>
// <time, weight, idx>
vector<int> Solution::assignTasks(vector<int>& servers, vector<int>& tasks) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> st, sw;

	for (int i = 0 ; i < servers.size() ; ++i) {
		sw.emplace(pair<int, int>(servers[i], i));
	}

	vector<int> result(tasks.size(), 0);
	int curT = 0;
	int ti = 0;

	while (ti < tasks.size()) {
		// curT is the time most early can process
		// if sw not empty, then process cur task
		// if sw empty(), speed up time to most early done server time
		curT = ti;
		if (sw.empty()) {
			curT = max(curT, st.top().first);
		}
		while (!st.empty() && st.top().first <= curT) {
			int idx = st.top().second;
			st.pop();
			sw.emplace(pair<int, int>(servers[idx], idx));
		}

		while (ti < tasks.size() && ti <= curT && !sw.empty()) {
			int sIdx = sw.top().second;
			sw.pop();
			st.emplace(pair<int, int>(curT + tasks[ti], sIdx));
			result[ti] = sIdx;
			++ti;
		}
	}
	return result;
}
