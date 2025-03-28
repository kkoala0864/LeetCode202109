#include <Solution.h>
#include <iostream>
#include <vector>

using std::vector;

bool check(vector<int> &cnt) {
	return cnt[0] && cnt[1] && cnt[2];
}

int Solution::numberOfSubstrings(string s) {

	int result = 0;
	int l = 0;
	vector<int> cnt(3, 0);
	for (int i = 0; i < s.size(); ++i) {
		while (l < s.size() && !check(cnt)) {
			++cnt[s[l++] - 'a'];
		}

		if (check(cnt))
			result += (s.size() - l + 1);
		--cnt[s[i] - 'a'];
	}
	return result;
}
