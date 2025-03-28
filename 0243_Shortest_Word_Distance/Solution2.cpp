#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::min;

int Solution::shortestDistance2(vector<string> &wordsDict, string word1, string word2) {
	int iter1 = -1, iter2 = -1;
	int result = wordsDict.size();

	for (int i = 0; i < wordsDict.size(); ++i) {
		if (wordsDict[i] != word1 && wordsDict[i] != word2)
			continue;
		if (wordsDict[i] == word1)
			iter1 = i;
		if (wordsDict[i] == word2)
			iter2 = i;
		if (iter1 != -1 && iter2 != -1) {
			result = min(result, abs(iter1 - iter2));
		}
	}
	return result;
}
