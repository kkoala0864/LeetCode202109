#include <Solution.h>
#include <iostream>
#include <string>
#include <cmath>

using std::cout;
using std::endl;
using std::string;
using std::to_string;

int Solution::countDigitOne(int n) {
	if (n < 2)
		return n;

	string nStr = to_string(n);

	int result = 0;
	for (int i = 0; i < nStr.size(); ++i) {
		int cur = i == 0 ? 1 : stoi(nStr.substr(0, i)) + 1;
		int post = 0;
		if (nStr[i] <= '1') {
			--cur;
		}
		cur *= pow(10, nStr.size() - 1 - i);
		if (nStr[i] == '1') {
			post = i == nStr.size() - 1 ? 1 : stoi(nStr.substr(i + 1)) + 1;
		}
		cur += post;
		result += cur;
	}
	return result;
}
