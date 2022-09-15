#include <Solution.h>
#include <iostream>
#include <unordered_map>
#include <algorithm>

using std::unordered_map;
using std::max;

int Solution::lengthOfLongestSubstringTwoDistinct(string s) {
	unordered_map<char, int> uMap;
	int distinctChar = 0;
	int result = 0;
	int l = 0;
	for (int i = 0 ; i < s.size() ; ++i) {
		++uMap[s[i]];
		if (uMap[s[i]] == 1) ++distinctChar;
		while (l <= i && distinctChar > 2) {
			--uMap[s[l]];
			if (uMap[s[l]] == 0) {
				uMap.erase(s[l]);
				--distinctChar;
			}
			++l;
		}
		result = max(result, i - l + 1);
	}
	return result;
}
