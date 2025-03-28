#include <Solution.h>
#include <iostream>

string Solution::addSpaces(string s, vector<int> &spaces) {
	string result;
	int si = 0;
	for (int i = 0; i < s.size(); ++i) {
		if (si < spaces.size() && i == spaces[si]) {
			result.push_back(' ');
			++si;
		}
		result.push_back(s[i]);
	}
	return result;
}
