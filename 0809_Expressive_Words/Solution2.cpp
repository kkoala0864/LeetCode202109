#include <Solution.h>
#include <iostream>

bool check(const string &s, const string &w) {
	int si = 0, wi = 0;
	if (s.size() < w.size())
		return false;
	while (si < s.size() && wi < w.size()) {
		if (s[si] != w[wi])
			return false;
		int scnt = 1, wcnt = 1;
		while (si < s.size() && s[si] == s[++si])
			++scnt;
		while (wi < w.size() && w[wi] == w[++wi])
			++wcnt;
		if (scnt < wcnt || (scnt > wcnt && scnt < 3))
			return false;
	}
	return si == s.size();
}

int Solution::expressiveWords2(string s, vector<string> &words) {
	int result = 0;
	for (const auto &iter : words) {
		if (check(s, iter))
			++result;
	}
	return result;
}
