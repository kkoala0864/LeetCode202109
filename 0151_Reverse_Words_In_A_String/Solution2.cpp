#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;
using std::swap;

string Solution::reverseWords2(string s) {
	while (s.back() == ' ')
		s.pop_back();

	int l = 0, r = s.size() - 1;
	while (l < r) {
		swap(s[l++], s[r--]);
	}
	while (s.back() == ' ')
		s.pop_back();

	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == ' ')
			continue;
		int l = i, r = i;
		while (r < s.size() - 1 && s[r + 1] != ' ')
			++r;
		i = r;
		while (l < r) {
			swap(s[l++], s[r--]);
		}
	}
	string result;
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] != ' ' || result.back() != ' ')
			result.push_back(s[i]);
	}
	return result;
}
