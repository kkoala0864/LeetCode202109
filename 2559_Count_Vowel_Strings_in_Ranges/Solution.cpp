#include <Solution.h>
#include <iostream>

bool isVowel(char a) {
	return a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u';
}

vector<int> Solution::vowelStrings(vector<string> &words, vector<vector<int>> &queries) {
	vector<int> preCnt;

	int curCnt = 0;
	for (const auto &w : words) {
		if (isVowel(w[0]) && isVowel(w.back())) {
			++curCnt;
		}
		preCnt.emplace_back(curCnt);
	}
	vector<int> result;
	for (const auto &q : queries) {
		int v = preCnt[q[1]];
		if (q[0] > 0) {
			v -= preCnt[q[0] - 1];
		}
		result.emplace_back(v);
	}
	return result;
}
