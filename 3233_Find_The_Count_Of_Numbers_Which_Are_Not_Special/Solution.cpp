#include <Solution.h>
#include <iostream>
#include <vector>

using std::vector;

int Solution::nonSpecialCount(int l, int r) {
	int ls = sqrt(l);
	int rs = sqrt(r);
	vector<int> prime(rs + 1, true);
	int result = r - l + 1;
	prime[0] = prime[1] = false;
	for (int i = 2; i <= rs; ++i) {
		if (!prime[i])
			continue;
		int v = i * i;
		if (l <= v && v <= r)
			--result;

		for (int j = 2; (j * i) <= rs; ++j) {
			prime[j * i] = false;
		}
	}
	return result;
}
