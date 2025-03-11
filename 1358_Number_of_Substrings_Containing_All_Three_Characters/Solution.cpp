#include <Solution.h>
#include <iostream>
#include <unordered_map>

using std::unordered_map;

// 0 1 2 3 4 5
int Solution::numberOfSubstrings(string s) {

	int result = 0;
	int l = 0;
	unordered_map<char, int> cnt;
	for (int i = 0 ; i < s.size() ; ++i) {
		while (l < s.size() && cnt.size() < 3) {
			++cnt[s[l++]];
		}

		if (cnt.size() == 3) result += (s.size() - l + 1);
		--cnt[s[i]];
		if (cnt[s[i]] == 0) cnt.erase(s[i]);
	}
	return result;
}
