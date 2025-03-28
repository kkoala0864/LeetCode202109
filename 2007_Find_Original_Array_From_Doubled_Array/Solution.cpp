#include <Solution.h>
#include <iostream>

vector<int> Solution::findOriginalArray(vector<int> &changed) {
	int size = changed.size();
	if (size == 0 || size & 1)
		return {};
	vector<int> cnt(1e5 + 1, 0);

	for (const auto &c : changed)
		++cnt[c];
	vector<int> result;

	if (cnt[0] & 1)
		return {};
	cnt[0] = cnt[0] >> 1;
	for (int j = 0; j < cnt[0]; ++j)
		result.emplace_back(0);

	for (int i = 1; i <= 50000; ++i) {
		if (cnt[i] == 0)
			continue;
		if (cnt[i] > 0) {
			if (cnt[i] <= cnt[i << 1]) {
				for (int j = 0; j < cnt[i]; ++j) {
					result.emplace_back(i);
					--cnt[i << 1];
				}
			} else {
				return {};
			}
		}
	}
	return result;
}
