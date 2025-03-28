#include <Solution.h>
#include <iostream>
#include <climits>
#include <string>

using std::string;
using std::swap;
using std::to_string;

int Solution::reverse2(int x) {
	if (x == 0)
		return 0;
	bool neg = x < 0;
	string str = to_string(abs(x));
	while (!str.empty() && str.back() == '0')
		str.pop_back();
	int start = 0, end = str.size() - 1;
	while (start < end) {
		swap(str[start], str[end]);
		++start;
		--end;
	}

	long long result = stoll(str);
	if (neg)
		result = -result;
	return result > INT_MAX || result < INT_MIN ? 0 : result;
}
