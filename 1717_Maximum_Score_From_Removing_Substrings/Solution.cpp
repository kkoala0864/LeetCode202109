#include <Solution.h>

int getScore(const string& pattern, int v, string& s) {
	string rest;
	int score = 0;
	for (int i = 0 ; i < s.size() ; ++i) {
		if (!rest.empty() && s[i] == pattern[1] && rest.back() == pattern[0]) {
			rest.pop_back();
			score += v;
		} else {
			rest.push_back(s[i]);
		}
	}
	s = move(rest);
	return score;
}

int Solution::maximumGain(string s, int x, int y) {
	int result = 0;
	if (x > y) {
		result = getScore("ab", x, s) + getScore("ba", y, s);
	} else {
		result = getScore("ba", y, s) + getScore("ab", x, s);
	}
	return result;
}
