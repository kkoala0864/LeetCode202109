#include <Solution.h>
#include <iostream>
#include <vector>
using std::vector;

string Solution::rearrangeString(string s, int k) {
	vector<int> lastIdx(26, -400000), cnt(26, 0);

	for (const auto &c : s)
		++cnt[c - 'a'];
	string result;
	while (result.size() < s.size()) {
		bool find = false;
		char c;
		for (int i = 0; i < 26; ++i) {
			if (cnt[i] == 0)
				continue;
			int diff = result.size() - lastIdx[i];
			if (find) {
				if (diff >= k && (cnt[i] > cnt[c - 'a'])) {
					c = i + 'a';
				}
			} else {
				if (diff >= k) {
					c = i + 'a';
					find = true;
				}
			}
		}
		if (!find)
			return "";
		result.push_back(c);
		lastIdx[c - 'a'] = result.size() - 1;
		--cnt[c - 'a'];
	}
	return result;
}
