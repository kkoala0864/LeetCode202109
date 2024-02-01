#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::max;

string Solution::mergeAlternately(string word1, string word2) {
	int n = max(word1.size(), word2.size());
	string result;

	for (int i = 0 ; i < n ; ++i) {
		if (i < word1.size()) result.push_back(word1[i]);
		if (i < word2.size()) result.push_back(word2[i]);
	}
	return result;
}
