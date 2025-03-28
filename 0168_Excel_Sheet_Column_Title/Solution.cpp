#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::reverse;

string Solution::convertToTitle(int columnNumber) {
	string result("");
	while (columnNumber > 0) {
		--columnNumber;
		result.push_back((columnNumber) % 26 + 'A');
		columnNumber /= 26;
	}

	reverse(result.begin(), result.end());
	return result;
}
