#include <Solution.h>
#include <iostream>
#include <unordered_map>
#include <algorithm>

using std::unordered_map;
using std::swap;
using std::min;
using std::cout;
using std::endl;

int Solution::longestPalindrome2(vector<string>& words) {
	unordered_map<string, int> strToCnt;

	int result = 0;
	for (const auto& w : words) ++strToCnt[w];

	bool duplicate = false;
	for (const auto& w : words) {
		if (strToCnt[w] == 0) continue;
		string rev = w;
		swap(rev[0], rev[1]);
		int cnt = rev[0] == rev[1] ? strToCnt[w] / 2 : min(strToCnt[w], strToCnt[rev]);
		result += (cnt * 2 * 2);
		strToCnt[w] -= cnt;
		strToCnt[rev] -= cnt;
	}
	for (const auto& e : strToCnt) {
		if (e.first[0] == e.first[1] && e.second > 0) {
			result += 2;
			break;
		}
	}
	return result;
}
