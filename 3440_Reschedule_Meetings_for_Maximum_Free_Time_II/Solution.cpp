#include <Solution.h>
#include <iostream>
#include <algorithm>
#include <map>

using std::cout;
using std::endl;
using std::map;
using std::max;
using std::sort;

int Solution::maxFreeTime(int eventTime, vector<int> &startTime, vector<int> &endTime) {
	vector<vector<int>> free;
	map<int, vector<int>> fi;

	int cur = 0;
	for (int i = 0; i < startTime.size(); ++i) {
		free.push_back({startTime[i] - cur, cur, startTime[i]});
		fi[startTime[i] - cur].emplace_back(i);
		cur = endTime[i];
	}

	free.push_back({eventTime - cur, cur, eventTime});
	fi[eventTime - cur].emplace_back(free.size() - 1);

	int result = 0;
	for (int i = 0; (i + 1) < free.size(); ++i) {
		int os = free[i + 1][1] - free[i][2];

		auto iter = fi.lower_bound(os);

		bool find = false;
		while (iter != fi.end()) {
			for (const auto &v : iter->second) {
				if (v != i && v != (i + 1)) {
					find = true;
					break;
				}
			}
			if (find)
				break;
			++iter;
		}
		if (find)
			result = max(result, free[i + 1][2] - free[i][1]);
		else
			result = max(result, free[i][0] + free[i + 1][0]);
	}
	return result;
}
