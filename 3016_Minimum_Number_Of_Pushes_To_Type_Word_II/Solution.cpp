#include <Solution.h>
#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::sort;

int Solution::minimumPushes(string word) {
	vector<int> cnt(26, 0);
	for (const auto& c : word) ++cnt[c-'a'];
	sort(cnt.begin(), cnt.end(), std::greater<int>());

	int result = 0;
	for (int i = 0 ; i < 26 ; ++i) {
		int v = (i / 8 + 1) * cnt[i];
		result += v;
	}
	return result;

}
