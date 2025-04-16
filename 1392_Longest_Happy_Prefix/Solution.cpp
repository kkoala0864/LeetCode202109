#include <Solution.h>
#include <iostream>
#include <vector>

vector<int> KMP(const string& s) {
	vector<int> lps(s.size(), 0);

	for (int i = 1 ; i < s.size() ; ++i) {
		int idx = lps[i-1];

		while (idx > 0 && s[idx] != s[i]) {
			idx = lps[idx - 1];
		}
		lps[i] = idx + (s[idx] == s[i]);
	}
	return lps;
}

string Solution::longestPrefix(string s) {
	auto lps = KMP(s);
	return lps.back() == 0 ? "" : s.substr(0, lps.back());
}
