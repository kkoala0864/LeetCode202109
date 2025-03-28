#include <Solution.h>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <climits>

using std::min;
using std::unordered_map;
/*
int Solution::shortestDistance(vector<string>& wordsDict, string word1, string word2) {
        unordered_map<string, vector<int>> uMap;

        for (int i = 0 ; i < wordsDict.size() ; ++i) {
                if (uMap.find(wordsDict[i]) == uMap.end()) {
                        uMap[wordsDict[i]] = vector<int>();
                }
                uMap[wordsDict[i]].emplace_back(i);
        }

        int result = INT_MAX;
        for (const auto& first : uMap[word1]) {
                for (const auto& second : uMap[word2]) {
                        result = min(abs(first - second), result);
                        if (result == 1) return 1;
                }
        }
        return result;
}
*/
int Solution::shortestDistance(vector<string> &wordsDict, string word1, string word2) {
	int i1 = -1, i2 = -1, result = INT_MAX;
	for (int i = 0; i < wordsDict.size(); ++i) {
		if (wordsDict[i] == word1) {
			if (i2 != -1) {
				result = min(i - i2, result);
			}
			i1 = i;
		} else if (wordsDict[i] == word2) {
			if (i1 != -1) {
				result = min(i - i1, result);
			}
			i2 = i;
		}
	}
	return result;
}
