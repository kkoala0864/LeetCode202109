#include <Solution.h>

vector<int> getLPS(const string& s) {
	int size = s.size();
	vector<int> lps(size, 0);

	for (int i = 1 ; i < size ; ++i) {
		int idx = lps[i-1];
		while (idx > 0 && s[i] != s[idx]) {
			idx = lps[idx-1];
		}
		lps[i] = idx + (s[i] == s[idx]);
	}
	return lps;
}

int getLastKMP(const string& s, int l, const vector<int>& lps) {
	if (l == s.size()) return 0;
	string tmp = s.substr(l);

	vector<int> k(tmp.size(), 0);
	k[0] = s[0] == tmp[0];
	for (int i = 1 ; i < tmp.size() ; ++i) {
		int idx = k[i-1];
		while (idx > 0 && s[idx] != tmp[i]) {
			idx = lps[idx-1];
		}
		k[i] = idx + (s[idx] == tmp[i]);
	}
	return k.back();
}

int Solution::minimumTimeToInitialState(string word, int k) {
	vector<int> lps = getLPS(word);
	int size = word.size();
	int rest = getLastKMP(word, k, lps);
	while (rest > 0 && (size - rest) % k) {
		int v = min((((size - rest) / k) * k) + k, size);
		rest = getLastKMP(word, v, lps);
	}
	return ((size - rest) / k) + ((size - rest) % k > 0);
}
