#include <Solution.h>

// rolling hash
bool check(const string& s, int len, unordered_map<int, int>& lm) {
	unordered_set<unsigned long long> hashSet;
	unsigned long long base = 1315423911ULL;
	unsigned long long v = 0;
	unsigned long long powerLen = 1;
	for (unsigned long long i = 1 ; i <= len ; ++i) {
		powerLen *= base;
	}

	// sliding window to get string hash
	for (int i = 0 ; i < s.size() ; ++i) {
		v *= base;
		v += (s[i] - 'a');
		if (i >= len) {
			v -= ((unsigned long long)(s[i-len] - 'a') * powerLen);
		}
		if (i >= len - 1) {
			if (hashSet.count(v)) {
				lm[len] = i - len + 1;
				return true;
			}
			hashSet.emplace(v);
		}
	}
	return false;
}

// there is exist monotonic in string length
string Solution::longestDupSubstring(string s) {
	int l = 1, r = s.size() - 1;
	int mid = 0;
	unordered_map<int, int> lm;
	string result;
	string str;

	while (l < r) {
		mid = r - ((r - l) >> 1);
		if (check(s, mid, lm)) {
			l = mid;
		} else {
			r = mid - 1;
		}
	}
	if (check(s, l, lm)) {
		return s.substr(lm[l], l);
	} else {
		return "";
	}
}

/*
// dp[i][j] = dp[i-1][j-1] + 1;
// is there exist i, j are same substring
// assume i => s(i), len(i);
// assume j => s(j), len(j);
// so there is exist two string [s(i).....s(i) + len(i) -1], [s(j).....s(j) + len(j) -1] => duplicate substring and is not same string
string Solution::longestDupSubstring(string s) {
	int size = s.size();
	vector<int> dp(size + 1, 0), next(size + 1, 0);

	int maxLen = 0;
	int ri = -1;
	for (int i = 0 ; i < size ; ++i) {
		for (int j = 0 ; j < i ; ++j) {
			if (s[i] == s[j]) {
				next[j+1] = dp[j] + 1;
				if (next[j+1] > maxLen) {
					maxLen = next[j+1];
					ri = i - next[j+1] + 1;
				}
			} else {
				next[j+1] = 0;
			}
		}
		swap(dp, next);
	}
	return ri == -1 ? "" : s.substr(ri, maxLen);
}
*/
