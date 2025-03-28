#include <Solution.h>
#include <iostream>
#include <climits>
#include <algorithm>

using std::cout;
using std::endl;
using std::min;

int Solution::shortestWordDistance(vector<string> &wordsDict, string word1, string word2) {
	int result = INT_MAX;
	int i1 = -1, i2 = -1;
	bool same = word1 == word2;
	for (int i = 0; i < wordsDict.size(); ++i) {
		if (wordsDict[i] == word1) {
			if (same) {
				if (i1 != -1)
					result = min(i - i1, result);
			} else {
				if (i2 != -1)
					result = min(i - i2, result);
			}
			i1 = i;
		} else if (wordsDict[i] == word2) {
			if (!same) {
				if (i1 != -1)
					result = min(i - i1, result);
				i2 = i;
			}
		}
	}
	return result;
}
