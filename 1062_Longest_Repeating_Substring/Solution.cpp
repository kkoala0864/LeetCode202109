#include <Solution.h>
#include <iostream>
#include <algorithm>
#include <unordered_set>

using std::max;
using std::unordered_set;

int Solution::longestRepeatingSubstring(string s) {
	unordered_set<string> us;
	int maxlen = 0;

	for (int len = 1 ; len < s.size() ; ++len) {
		for (int i = 0 ; (i + len - 1) < s.size() ; ++i) {
			string str = s.substr(i, len);
			if (us.count(str)) {
				maxlen = len;
				break;
			} else {
				us.emplace(str);
			}
		}
		us.clear();
		if (maxlen < len) break;
	}
	return maxlen;
}
