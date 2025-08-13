#include <Solution.h>

long long Solution::maxTotal(vector<int>& value, vector<int>& limit) {
	vector<pair<int, long long>> vlv;

	for (int i = 0 ; i < value.size() ; ++i) {
		vlv.emplace_back(pair<int, long long>(limit[i], (long long)value[i]));
	}

	auto cmp = [](const pair<int, long long>& lhs, const pair<int, long long>& rhs) {
		return lhs.first == rhs.first ? lhs.second > rhs.second : lhs.first < rhs.first;
	};
	sort(vlv.begin(), vlv.end(), cmp);
	vector<bool> visited(vlv.size(), false);
	long long result = 0;
	int curCnt = 0;
	int vi = 0;

	for (int i = 0 ; i < vlv.size() ; ++i) {
		if (vlv[i].first <= curCnt) continue;

		result += vlv[i].second;
		++curCnt;
		visited[i] = true;
		int nextCnt = curCnt;
		for (; vi < vlv.size() && vlv[vi].first < curCnt ; ++vi) {
			if (visited[vi]) --nextCnt;
		}
		curCnt = nextCnt;
	}
	return result;
}
