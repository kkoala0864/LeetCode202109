#include <Solution.h>
#include <iostream>

bool isExpressive(const string &s, const string &word) {
	int i = 0, j = 0;
	while (i < s.size() && j < word.size()) {
		if (s[i] != word[j])
			return false;
		int sCnt = 1, wordCnt = 1;
		while (i < s.size() && s[i] == s[++i])
			++sCnt;
		while (j < word.size() && word[j] == word[++j])
			++wordCnt;
		if (wordCnt != sCnt && (wordCnt > sCnt || sCnt < 3))
			return false;
	}
	return i == s.size() && j == word.size();
}

int Solution::expressiveWords(string s, vector<string> &words) {
	int result = 0;
	for (const auto &word : words) {
		if (isExpressive(s, word))
			++result;
	}
	return result;
}
