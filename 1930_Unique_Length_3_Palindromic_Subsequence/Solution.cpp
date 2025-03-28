#include <Solution.h>
#include <iostream>
#include <vector>
#include <algorithm>

using std::max;
using std::min;
using std::pair;
using std::vector;

int Solution::countPalindromicSubsequence(string s) {
	int size = s.size();
	vector<pair<int, int>> idx(26, pair<int, int>(size, 0));
	vector<vector<int>> preDiff;

	vector<int> curDiff(26, 0);

	for (int i = 0; i < size; ++i) {
		idx[s[i] - 'a'].first = min(idx[s[i] - 'a'].first, i);
		idx[s[i] - 'a'].second = max(idx[s[i] - 'a'].second, i);
		++curDiff[s[i] - 'a'];
		preDiff.emplace_back(curDiff);
	}

	int result = 0;
	for (int i = 0; i < 26; ++i) {
		if ((idx[i].second - idx[i].first + 1) < 3)
			continue;
		for (int j = 0; j < 26; ++j) {
			int uniqueCnt = preDiff[idx[i].second - 1][j] - preDiff[idx[i].first][j];
			result += uniqueCnt > 0 ? 1 : 0;
		}
	}
	return result;
}
