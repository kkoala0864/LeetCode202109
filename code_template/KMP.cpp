#include <Solution.h>

vector<int> computeLPS(const string &pattern) {
	int m = pattern.size();
	vector<int> lps(m, 0);

	for (int i = 1 ; i < pattern.size() ; ++i) {
		int j = lps[i-1];
		while (j > 0 && pattern[i] != pattern[j]) {
			j = lps[j-1];
		}
		lps[i] = j + (pattern[i] == pattern[j]);
	}

	return lps;
}

vector<int> Solution::KMPsearch(const string &text, const string &pattern) {
	int n = text.size(), m = pattern.size();
	vector<int> lps = computeLPS(pattern);
	vector<int> result(n, 0);

	result[0] = (text[0] == pattern[0]);
	for (int i = 1 ; i < text.size() ; ++i) {
		int j = result[i-1];
		while (j > 0 && text[i] != pattern[j]) {
			j = lps[j-1];
		}
		result[i] = j + (text[i] == pattern[j]);
	}
	return result;
}
