#include <Solution.h>
#include <iostream>

string Solution::maximumOddBinaryNumber(string s) {
	string result = "1";
	int cnt0 = 0;
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == '0')
			++cnt0;
	}
	return string(s.size() - cnt0 - 1, '1') + string(cnt0, '0') + "1";
}
