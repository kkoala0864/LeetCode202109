#include <Solution.h>
#include <iostream>
#include <unordered_map>

using std::cout;
using std::endl;
using std::unordered_map;

int Solution::countHomogenous(string s) {
	int mod = 1e9 + 7;
	int result = 0;
	int cnt = 0;
	for (int i = 0; i < s.size(); ++i) {
		if (i == 0 || s[i] != s[i - 1]) {
			cnt = 0;
		}
		++cnt;
		result += cnt;
		result %= mod;
	}

	return result;
}
