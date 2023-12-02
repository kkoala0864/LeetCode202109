#include <Solution.h>
#include <iostream>

int Solution::countCharacters(vector<string>& words, string chars) {
	vector<int> cnt(26, 0);

	for (const auto& c : chars) {
		++cnt[c-'a'];
	}

	int result = 0;
	for (const auto& w : words) {
		vector<int> tmp = cnt;
		int i = 0;
		for (; i < w.size() ; ++i) {
			if (tmp[w[i]-'a'] > 0) {
				--tmp[w[i]-'a'];
			} else break;
		}
		if (i == w.size()) {
			result += i;
		}
	}
	return result;
}
