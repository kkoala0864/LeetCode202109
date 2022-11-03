#include <Solution.h>
#include <iostream>

int Solution::strStr2(string haystack, string needle) {
	if (needle.empty()) return 0;
	if (haystack.size() < needle.size()) return -1;
	int nsize = needle.size();
	int hsize = haystack.size();

	for (int i = 0 ; i < (hsize - nsize + 1) ; ++i) {
		string curStr = haystack.substr(i, nsize);
		if (curStr == needle) return i;
	}
	return -1;
}
