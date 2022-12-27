#include <Solution.h>
#include <iostream>
#include <vector>
#include <algorithm>

using std::min;
using std::vector;

int Solution::takeCharacters(string s, int k) {
	int size = s.size();
	vector<int> cnt(3, 0);

	for (const auto& c : s) ++cnt[c-'a'];

	for (int i = 0 ; i < 3 ; ++i) {
		if (cnt[i] < k) return -1;
	}
	int l = 0;
	int result = size;
	for (int i = 0 ; i < size ; ++i) {
		int idx = s[i] - 'a';

		--cnt[idx];
		while (cnt[idx] < k) {
			++cnt[s[l++]-'a'];
		}

		result = min(result, size - (i - l + 1));
	}
	return result;
}
