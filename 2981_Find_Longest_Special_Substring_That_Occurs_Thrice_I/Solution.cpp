#include <Solution.h>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using std::max;
using std::min;
using std::unordered_map;

bool isBeauty(const string& s) {
	for (int i = 0 ; i < s.size() ; ++i) {
		if (s[i] == s[0]) continue;
		return false;
	}
	return true;
}

int Solution::maximumLength(string s) {
	int size = s.size();
	int result = 0;

	for (int i = s.size() - 2 ; i > 0 ; --i) {
		unordered_map<string, int> m;
		for(int j = 0 ; j <= (size - i) ; ++j) {
			string sub = s.substr(j, i);
			if (!isBeauty(sub)) continue;
			++m[sub];
			if (m[sub] > 2) {
				return i;
			}
		}
	}
	return -1;
}
