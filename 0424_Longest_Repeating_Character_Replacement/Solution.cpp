#include <Solution.h>
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using std::max;
using std::vector;

int Solution::characterReplacement(string s, int k) {
	int start = 0;
	vector<int> cnt(26, 0);
	int result = INT_MIN;
	int maxCnt = INT_MIN;
	for (int end = start; end < s.size(); ++end) {
		++cnt[s[end] - 'A'];
		maxCnt = max(maxCnt, cnt[s[end] - 'A']);
		while ((end - start + 1) - maxCnt > k) {
			--cnt[s[start] - 'A'];
			++start;
			int tmpMaxCnt = INT_MIN;
			for (const auto &iter : cnt)
				tmpMaxCnt = max(tmpMaxCnt, iter);
			maxCnt = tmpMaxCnt;
		}
		result = max(result, (end - start + 1));
	}
	return result;
}
