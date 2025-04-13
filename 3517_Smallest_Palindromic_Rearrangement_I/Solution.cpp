#include <Solution.h>
#include <iostream>
#include <vector>

string Solution::smallestPalindrome(string s) {
	vector<int> cnt(26, 0);
	for (const auto& c : s) {
		++cnt[c-'a'];
	}

	int size = s.size();
	char c = '#';
	int idx = 0;
	for (int i = 0 ; i < 26 ; ++i) {
		while (cnt[i] > 1) {
			s[idx] = i + 'a';
			s[size - 1 - idx] = i + 'a';
			++idx;
			cnt[i] -= 2;
		}
		if (cnt[i] == 1) c = i + 'a';
	}

	if (c != '#') s[idx] = c;
	return s;
}
