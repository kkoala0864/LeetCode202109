#include <Solution.h>
#include <iostream>
#include <vector>

vector<int> getLPS(const string &s) {
	vector<int> lps(s.size(), 0);

	for (int i = 1; i < s.size(); ++i) {
		int idx = lps[i - 1];
		while (idx > 0 && s[i] != s[idx]) {
			idx = lps[idx - 1];
		}
		lps[i] = idx + (s[i] == s[idx]);
	}
	return lps;
}

vector<int> getMaxCom(const vector<int> &lps, const string &s, const string &p) {
	vector<int> maxCom(s.size(), 0);

	int maxLen = maxCom[0] = (s[0] == p[0]);

	for (int i = 1; i < s.size(); ++i) {
		int idx = maxCom[i - 1];
		while (idx > 0 && s[i] != p[idx]) {
			idx = lps[idx - 1];
		}
		maxCom[i] = idx + (s[i] == p[idx]);
	}
	return maxCom;
}

bool check(const string &s, int l, int r) {
	while (l < r) {
		if (s[l++] != s[r--])
			return false;
	}
	return true;
}

int Solution::longestPalindrome(string s, string t) {
	int result = 0;
	vector<int> sPreMax(s.size(), 1);
	vector<int> tPostMax(t.size(), 1);

	for (int i = 0; i < s.size(); ++i) {
		for (int j = i; j < s.size(); ++j) {
			if (check(s, i, j)) {
				sPreMax[i] = max(sPreMax[i], j - i + 1);
			}
			result = max(result, sPreMax[i]);
		}
	}
	for (int i = 0; i < t.size(); ++i) {
		for (int j = i; j < t.size(); ++j) {
			if (check(t, i, j)) {
				tPostMax[j] = max(tPostMax[j], j - i + 1);
			}
			result = max(result, tPostMax[j]);
		}
	}

	string rs = s;
	reverse(rs.begin(), rs.end());

	for (int i = 0; i < s.size(); ++i) {
		string ss = rs.substr(i);
		vector<int> lps(s.size(), 0);
		vector<int> maxCom = getMaxCom(lps, t, ss);
		for (int j = 0; j < maxCom.size(); ++j) {
			int len = maxCom[j];
			int tl = j - len + 1;
			int se = s.size() - i - 1;
			int tAppend = (tl == 0) ? 0 : tPostMax[tl - 1];
			int sAppend = (se >= s.size() - 1) ? 0 : sPreMax[se + 1];
			result = max({result, (len << 1) + tAppend, (len << 1) + sAppend});
		}
	}
	return result;
}
