#include <Solution.h>
#include <iostream>

using std::swap;
void Solution::reverseString(vector<char> &s) {
	int start = 0, end = s.size() - 1;
	while (start < end)
		swap(s[start++], s[end--]);
}
