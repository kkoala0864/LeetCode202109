#include <Solution.h>
#include <iostream>

using std::pair;

int Solution::expressiveWords3(string s, vector<string> &words) {
	vector<pair<char, int>> charCnt;

	for (int i = 0; i < s.size(); ++i) {
		int cnt = 1;
		while (i < s.size() - 1 && s[i] == s[i + 1]) {
			++cnt;
			++i;
		}
		charCnt.emplace_back(pair<char, int>(s[i], cnt));
	}
	int result = 0;
	for (const auto &w : words) {
		if (w.size() > s.size())
			continue;
		int charIdx = 0;
		for (int i = 0; i < w.size(); ++i) {
			int cnt = 1;
			while (i < w.size() - 1 && w[i] == w[i + 1]) {
				++cnt;
				++i;
			}

			if ((charCnt[charIdx].first != w[i]) || (charCnt[charIdx].second < cnt) || (charCnt[charIdx].second < 3 && charCnt[charIdx].second != cnt)) {
				break;
			}
			++charIdx;
		}
		if (charIdx == charCnt.size())
			++result;
	}
	return result;
}
