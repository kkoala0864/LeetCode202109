#include <Solution.h>
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

void getLPS(const string &s, vector<int> &lps) {
	int i = 1;
	int len = 0;

	while (i < s.size()) {
		if (s[i] == s[len]) {
			++len;
			lps[i] = len;
			++i;
		} else {
			if (len == 0) {
				lps[i] = 0;
				++i;
			} else {
				len = lps[len - 1];
			}
		}
	}
}

int kmp_compare(const string &s, const string &pattern) {
	vector<int> lps(pattern.size(), 0);
	getLPS(pattern, lps);

	int i = 0;
	int j = 0;
	int n = s.size();
	int m = pattern.size();

	while (i < n) {
		if (s[i] == pattern[j]) {
			++i;
			++j;
		}
		if (j == m) {
			break;
		} else if (i < n && s[i] != pattern[j]) {
			if (j == 0) {
				++i;
			} else {
				j = lps[j - 1];
			}
		}
	}
	if (j == m)
		return i - j;
	return -1;
}

string Solution::removeOccurrences(string s, string part) {
	int idx = kmp_compare(s, part);
	string tmp;

	while (idx != -1) {
		if (idx > 0) {
			tmp = s.substr(0, idx);
		}
		tmp += s.substr(idx + part.size());
		s = move(tmp);
		idx = kmp_compare(s, part);
	}
	return s;
}
