#include <Solution.h>

int Solution::maxSumDistinctTriplet(vector<int>& x, vector<int>& y) {
	vector<pair<int, int>> list;
	for (int i = 0 ; i < x.size() ; ++i) {
		list.emplace_back(pair<int, int>(y[i], x[i]));
	}
	sort(list.begin(), list.end(), greater<>());

	int result = 0;
	unordered_set<int> us;
	int cnt = 0;
	for (int i = 0 ; i < list.size() && cnt < 3 ; ++i) {
		if (us.count(list[i].second)) continue;
		result += list[i].first;
		us.emplace(list[i].second);
		++cnt;
	}
	if (cnt < 3) return -1;
	return result;
}
