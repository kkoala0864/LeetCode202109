#include <Solution.h>

int Solution::maxDifference(string s) {
	int oddMax = 0, evenMin = s.size();

	vector<int> cnt(26, 0);
	for (const auto& c : s) ++cnt[c-'a'];
	for (int i = 0 ; i < 26 ; ++i) {
		if (cnt[i] == 0) continue;
		if (cnt[i] & 1) {
			oddMax = max(oddMax, cnt[i]);
		} else {
			evenMin = min(evenMin, cnt[i]);
		}
	}
	return oddMax - evenMin;
}
