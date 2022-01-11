#include <Solution.h>
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using std::vector;
using std::max;

int Solution::characterReplacement3(string s, int k) {
	vector<int> cnt(26, 0);
	int b = 0, e = 0;
	int maxCnt = 0;
	int result = 0;
	while (e < s.size()) {
		++cnt[s[e]-'A'];
		maxCnt = max(maxCnt, cnt[s[e]-'A']);
		++e;
		while ((e - b - maxCnt) > k) {
			--cnt[s[b]-'A'];
			++b;
			maxCnt = 0;
			for (int i = 0 ; i < 26 ; ++i) maxCnt = max(maxCnt, cnt[i]);
		}
		result = max(result, e - b);
	}
	return result;
}
