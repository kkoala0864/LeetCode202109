#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::sort;

int Solution::visibleMountains(vector<vector<int>> &peaks) {
	vector<vector<int>> list;
	for (int i = 0; i < peaks.size(); ++i) {
		list.emplace_back(vector<int>({peaks[i][0] - peaks[i][1], peaks[i][0] + peaks[i][1]}));
	}
	auto cmp = [](const vector<int> &lhs, const vector<int> &rhs) {
		return lhs[0] == rhs[0] ? lhs[1] > rhs[1] : lhs[0] < rhs[0];
	};
	sort(list.begin(), list.end(), cmp);

	vector<vector<int>> result;

	bool isPop = false;
	for (int i = 0; i < list.size(); ++i) {
		if (result.empty()) {
			result.emplace_back(list[i]);
		} else {
			if (result.back()[1] < list[i][1]) {
				if (isPop) {
					result.pop_back();
					isPop = false;
				}
				result.emplace_back(list[i]);
			} else if (result.back()[1] == list[i][1] && result.back()[0] == list[i][0]) {
				isPop = true;
			}
		}
	}
	if (isPop)
		result.pop_back();
	return result.size();
}
