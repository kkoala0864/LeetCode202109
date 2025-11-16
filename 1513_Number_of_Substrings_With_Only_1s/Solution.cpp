#include <Solution.h>

int Solution::numSub(string s) {
	int result = 0;
	int cnt = 0;
	int mod = 1e9 + 7;
	for (int i = 0 ; i < s.size() ; ++i) {
		if (s[i] == '0') cnt = 0;
		else {
			++cnt;
			result += cnt;
			result %= mod;
		}
	}
	return result;
}
