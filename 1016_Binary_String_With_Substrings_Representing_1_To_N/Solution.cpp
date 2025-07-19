#include <Solution.h>

bool Solution::queryString(string s, int n) {
	unordered_set<int> us;

	for (int i = 0 ; i < s.size() ; ++i) {
		long long cur = 0;
		for (int j = i ; j < s.size() ; ++j) {
			cur = cur << 1;
			cur += (s[j] - '0');
			if (cur > n) break;
			if (cur > 0) {
				us.emplace(cur);
			}
		}
	}
	return us.size() == n;
}
