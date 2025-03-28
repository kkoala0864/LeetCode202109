#include <Solution.h>
#include <iostream>
#include <unordered_set>

using std::unordered_set;

bool Solution::halvesAreAlike(string s) {
	unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
	int size = s.size();

	int cnt = 0;
	int i = 0;
	for (; i < (size >> 1); ++i) {
		if (vowels.count(s[i]) > 0) {
			++cnt;
		}
	}

	for (; i < size; ++i) {
		if (vowels.count(s[i]) > 0) {
			--cnt;
		}
	}
	return cnt == 0;
}
