#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::sort;
bool isPrefixAndSuffix(const string& s1, const string& s2) {
	if (s1.size() > s2.size()) return false;
	int i = 0;
	for (; i < s1.size() ; ++i) {
		if (s1[i] != s2[i]) break;
	}
	if (i != s1.size()) return false;
	i = 0;
	for (; i < s1.size() ; ++i) {
		if (s1[s1.size() - 1 - i] != s2[s2.size() - 1 - i]) break;
	}
	return i == s1.size();
}

int Solution::countPrefixSuffixPairs(vector<string>& words) {
	auto cmp = [](const string& lhs, const string& rhs) {
		return lhs.size() < rhs.size();
	};

	int size = words.size();
	int result = 0;
	for (int i = 0 ; i < size - 1 ; ++i) {
		for (int j = i + 1 ; j < size ; ++j) {
			if (isPrefixAndSuffix(words[i], words[j])) ++result;
		}
	}
	return result;
}
