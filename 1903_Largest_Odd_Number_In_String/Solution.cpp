#include <Solution.h>
#include <iostream>

string Solution::largestOddNumber(string num) {
	while (!num.empty() && ((num.back() - '0') & 1) == 0) {
		num.pop_back();
	}
	return num;
}
