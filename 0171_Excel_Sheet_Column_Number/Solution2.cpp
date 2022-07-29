#include <Solution.h>
#include <iostream>

int Solution::titleToNumber2(string columnTitle) {
	int result = 0;
	for (const auto& v : columnTitle) {
		result *= 26;
		result += (v - 'A' + 1);
	}
	return result;
}
