#include <Solution.h>
#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

string Solution::convert(string s, int numRows) {
	if (numRows == 1) return s;

	string result;
	int base = 2 * (numRows - 1);
	int iter = 0;
	for (int i = 0 ; i < numRows ; ++i) {
		int one = base - (2 * i);
		int two = 2 * i;
		iter = i;
		if (iter < s.size()) result.push_back(s[iter]);
		while (iter < s.size()) {
			if (one > 0) {
				iter += one;
				if (iter < s.size()) result.push_back(s[iter]);
			}
			if (two > 0) {
				iter += two;
				if (iter < s.size()) result.push_back(s[iter]);
			}
		}
	}
	return result;
}

