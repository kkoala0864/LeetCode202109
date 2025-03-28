#include <Solution.h>
#include <iostream>

vector<int> Solution::getModifiedArray(int length, vector<vector<int>> &updates) {
	vector<int> result;
	int curVal = 0;
	vector<int> cnt(length + 1, 0);
	for (const auto update : updates) {
		cnt[update[0]] += update[2];
		cnt[update[1] + 1] -= update[2];
	}

	for (int i = 0; i < length; ++i) {
		if (cnt[i] != 0)
			curVal += cnt[i];
		result.emplace_back(curVal);
	}
	return result;
}
