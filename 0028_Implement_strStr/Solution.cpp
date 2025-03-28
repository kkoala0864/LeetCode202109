#include <Solution.h>
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

vector<int> getLPS(const string &p) {
	int size = p.size();
	vector<int> lps(size, 0);

	for (int i = 1; i < size; ++i) {
		int j = lps[i - 1];
		while (j > 0 && p[i] != p[j]) {
			j = lps[j - 1];
		}
		lps[i] = j + (p[i] == p[j]);
	}
	return lps;
}

int Solution::strStr(string haystack, string needle) {
	vector<int> lps = getLPS(needle);
	vector<int> kmp;

	for (int i = 0; i < haystack.size(); ++i) {
		if (i == 0) {
			kmp.emplace_back(haystack[0] == needle[0]);
		} else {
			int j = kmp[i - 1];
			while (j > 0 && haystack[i] != needle[j]) {
				j = lps[j - 1];
			}
			kmp.emplace_back(j + (haystack[i] == needle[j]));
		}
		if (kmp.back() == needle.size())
			break;
	}
	return kmp.back() == needle.size() ? kmp.size() - needle.size() : -1;
}
