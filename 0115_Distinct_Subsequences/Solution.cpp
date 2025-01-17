#include <Solution.h>
#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

int Solution::numDistinct(string s, string t) {
	int sz = s.size();
	int tz = t.size();

	vector<long long> last(sz, 0), dp(sz, 0);

	for (int i = 0 ; i < sz ; ++i) {
		if (s[i] == t[0]) last[i] += 1;
	}

	for (int i = 1 ; i < tz ; ++i) {
		int cnt = 0;
		for (int j = 0 ; j < sz ; ++j) {
			if (s[j] == t[i]) {
				dp[j] = cnt;
			}
			if (s[j] == t[i-1]) cnt += last[j];
			if (cnt > INT_MAX) break;
		}
		swap(last, dp);
	}
	long long result = 0;
	for (int i = 0 ; i < sz ; ++i) {
		if (s[i] == t.back()) result += last[i];
	}
	return result;
}
