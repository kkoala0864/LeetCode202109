#include <Solution.h>
#include <iostream>

vector<int> Solution::countBits3(int n) {
	vector<int> result(n + 1, 0);

	int base = 2;
	for (int i = 1; i <= n; ++i) {
		if (i == base)
			base = base << 1;
		result[i] = result[i % (base >> 1)] + 1;
	}
	return result;
}
