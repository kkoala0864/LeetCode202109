#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::max;

int Solution::maxScore(string s) {
	int cnt0 = 0, cnt1 = 0;
	for (const auto& c : s) {
		if (c == '1') ++cnt1;
	}

	int result = 0;

	for (int i = 0 ; i < s.size() - 1 ; ++i) {
		if (s[i] == '0') ++cnt0;
		else --cnt1;
		result = max(result, cnt0 + cnt1);
	}
	return result;
}
