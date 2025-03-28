#include <Solution.h>
#include <iostream>

vector<int> Solution::relativeSortArray(vector<int> &arr1, vector<int> &arr2) {
	vector<int> cnt(1001, 0);

	for (const auto &v : arr1)
		++cnt[v];

	vector<int> result;
	for (const auto &v : arr2) {
		for (int i = 0; i < cnt[v]; ++i) {
			result.emplace_back(v);
		}
		cnt[v] = 0;
	}

	for (int i = 0; i <= 1000; ++i) {
		if (cnt[i] == 0)
			continue;
		for (int j = 0; j < cnt[i]; ++j)
			result.emplace_back(i);
	}
	return result;
}
