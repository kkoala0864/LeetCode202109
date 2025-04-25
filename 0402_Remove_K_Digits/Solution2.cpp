#include <Solution.h>
#include <iostream>

string Solution::removeKdigits2(string num, int k) {
	string result;
	for (int i = 0; i < num.size(); ++i) {
		while (!result.empty() && result.back() > num[i] && k-- > 0) {
			result.pop_back();
		}
		if (result.empty() && num[i] == '0')
			continue;
		result.push_back(num[i]);
	}
	while (!result.empty() && k-- > 0)
		result.pop_back();
	return result.empty() ? "0" : result;
}
