#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::min;

int Solution::shortestWordDistance2(vector<string> &wordsDict, string word1, string word2) {
	int result = INT_MAX;
	int lastIdx = -1;

	for (int i = 0; i < wordsDict.size(); ++i) {
		if (wordsDict[i] != word1 && wordsDict[i] != word2)
			continue;
		if (lastIdx != -1 && (wordsDict[i] != wordsDict[lastIdx] || word1 == word2)) {
			result = min(result, i - lastIdx);
		}
		lastIdx = i;
	}
	return result;
}
