#include <Solution.h>
#include <iostream>

bool Solution::repeatedSubstringPattern(string s) {
	int size = s.size();
	int h = size / 2;

	for (int i = 1; i <= h; ++i) {
		if (size % i != 0)
			continue;

		string temp = s.substr(0, i);

		int idx = i;
		string cmp;
		while (idx < size) {
			cmp = s.substr(idx, i);
			if (cmp != temp)
				break;
			idx += i;
		}
		if (idx == size)
			return true;
	}
	return false;
}
