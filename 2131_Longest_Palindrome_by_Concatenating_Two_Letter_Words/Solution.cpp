#include <Solution.h>
#include <iostream>
#include <unordered_map>
#include <algorithm>

using std::min;
using std::swap;
using std::unordered_map;

int Solution::longestPalindrome(vector<string> &words) {
	unordered_map<string, int> uMap;
	for (const auto &w : words)
		++uMap[w];

	int result = 0;
	for (auto &e : uMap) {
		if (e.first[0] == e.first[1]) {
			if (e.second > 1) {
				result += ((e.second / 2) * 4);
				e.second %= 2;
			}
		} else {
			string rev = {e.first[1], e.first[0]};
			if (uMap.find(rev) != uMap.end() && uMap[rev] > 0) {
				int val = min(uMap[rev], e.second);
				uMap[rev] -= val;
				e.second -= val;
				result += (4 * val);
			}
		}
	}
	for (const auto &e : uMap) {
		if (e.second > 0 && e.first[0] == e.first[1]) {
			result += 2;
			break;
		}
	}
	return result;
}
