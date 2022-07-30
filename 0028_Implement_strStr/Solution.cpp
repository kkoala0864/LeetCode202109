#include <Solution.h>
#include <iostream>

int Solution::strStr(string haystack, string needle) {
	if (needle == "") return 0;
	if (haystack.size() < needle.size()) return -1;
	int hi = 0;
	while (hi <= (haystack.size() - needle.size())) {
		if (haystack[hi] == needle[0]) {
			int ni = 0;
			int thi = hi;
			while (ni < needle.size() && haystack[thi] == needle[ni]) {
				++ni;
				++thi;
			}
			if (ni == needle.size()) return hi;
		}
		++hi;
	}
	return -1;
}
