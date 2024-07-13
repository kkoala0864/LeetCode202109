#include <Solution.h>
#include <iostream>

int getScore(string& s, const string& sub, int score) {
	string str;
	int result = 0;
	for (const auto& c : s) {
		if (c == sub[1]) {
			if (!str.empty() && str.back() == sub[0]) {
				str.pop_back();
				result += score;
				continue;
			}
		}
		str.push_back(c);
	}
	s = str;
	return result;
}

int Solution::maximumGain(string s, int x, int y) {
	int result = 0;
	if (x > y) {
		result += getScore(s, "ab", x);
		result += getScore(s, "ba", y);
	} else {
		result += getScore(s, "ba", y);
		result += getScore(s, "ab", x);
	}
	return result;
}
