#include <Solution.h>

bool Solution::hasSameDigits(string s) {
	while (s.size() > 2) {
		string tmp(s.size() - 1, '#');
		for (int i = 0 ; i < s.size() - 1 ; ++i) {
			tmp[i] = (s[i] - '0' + s[i+1] - '0') % 10 + '0';
		}
		s = std::move(tmp);
	}
	return s[0] == s[1];
}
