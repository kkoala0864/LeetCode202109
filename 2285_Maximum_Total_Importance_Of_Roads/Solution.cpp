#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::sort;

long long Solution::maximumImportance(int n, vector<vector<int>> &roads) {
	vector<int> cnt(n, 0);

	for (const auto &r : roads) {
		++cnt[r[0]];
		++cnt[r[1]];
	}

	sort(cnt.begin(), cnt.end(), std::greater<int>());

	long long result = 0;
	for (int i = 0; i < n; ++i) {
		result += (long long)cnt[i] * (long long)(n - i);
	}
	return result;
}
