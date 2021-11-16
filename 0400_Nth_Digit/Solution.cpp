#include <Solution.h>
#include <iostream>
#include <string>

using std::string;
using std::to_string;

int Solution::findNthDigit(int n) {
	int rest = n;
	for (int i = 0 ; pow(10, i) < (INT_MAX / 10) ; ++i) {
		long int lower = pow(10, i);
		long int upper = pow(10, i + 1);
		int offset = i + 1;
		long int size = upper - lower;

		if ((offset * size) < rest) {
			rest -= (offset * size);
		} else {
			int last = rest / offset;
			int idx = rest % offset;
			if (idx > 0) {
				string str = to_string(lower+last);
				return str[idx-1] - '0';
			} else {
				string str = to_string(lower+last-1);
				return str[i] - '0';
			}
		}
	}
	return 0;
}
