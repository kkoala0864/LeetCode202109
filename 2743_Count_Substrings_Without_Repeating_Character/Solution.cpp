#include <Solution.h>
#include <iostream>
#include <vector>

using std::vector;

int Solution::numberOfSpecialSubstrings(string s) {
	int l = 0;
	int result = 0;
	vector<int> cnt(26, 0);

	for (int i = 0; i < s.size(); ++i) {
		++cnt[s[i] - 'a'];

		while (cnt[s[i] - 'a'] > 1) {
			--cnt[s[l] - 'a'];
			++l;
		}
		result += (i - l + 1);
	}

	return result;
}
