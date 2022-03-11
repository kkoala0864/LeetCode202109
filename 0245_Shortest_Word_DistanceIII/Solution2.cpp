#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::min;

int Solution::shortestWordDistance2(vector<string>& wordsDict, string word1, string word2) {
	int i1 = -1, i2 = -1;
	bool same = word1 == word2;
	int result = wordsDict.size();

	for (int i = 0 ; i < wordsDict.size() ; ++i) {
		if (same) {
			if (wordsDict[i] == word1) {
				if (i1 != -1) result = min(result, i - i1);
				i1 = i;
			}
		} else {
			if (wordsDict[i] == word1) {
				if (i2 != -1) result = min(result, i - i2);
				i1 = i;
			}
			if (wordsDict[i] == word2) {
				if (i1 != -1) result = min(result, i - i1);
				i2 = i;
			}
		}
	}
	return result;
}
