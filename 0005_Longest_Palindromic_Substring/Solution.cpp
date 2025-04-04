#include <Solution.h>
#include <iostream>
#include <vector>
#include <algorithm>

using std::min;
using std::vector;
using std::cout;
using std::endl;
// manacher algorithm
//
// X {X X X X X X X X X X X X X X X X X X X X X} X X
//          j             ctr           i     mr
//
string Solution::longestPalindrome(string s) {
	string t(1, '#');
	for (int i = 0 ; i < s.size() ; ++i) {
		t.push_back(s[i]);
		t.push_back('#');
	}
	int n = t.size();

	vector<int> p(n, 0);
	int maxRight = -1;
	int maxCenter = -1;

	for (int i = 0 ; i < n ; ++i) {
		int r = 0;
		if (i <= maxRight) {
			int j = (maxCenter << 1) - i;
			r = min(p[j], maxRight - i);
			while (i - r >= 0 && i + r < n && t[i-r] == t[i+r]) {
				++r;
			}
		} else {
			while (i - r >= 0 && i + r < n && t[i-r] == t[i+r]) {
				++r;
			}
		}

		p[i] = r - 1;
		if (i + p[i] > maxRight) {
			maxRight = i + p[i];
			maxCenter = i;
		}
	}

	maxCenter = 0;
	int maxLen = -1;
	for (int i = 0 ; i < n ; ++i) {
		if (p[i] > maxLen) {
			maxLen = p[i];
			maxCenter = i;
		}
	}
	return s.substr((maxCenter - maxLen) >> 1, maxLen);
}
