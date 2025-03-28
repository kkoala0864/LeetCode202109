#include <Solution.h>
#include <iostream>
#include <vector>

using std::vector;

int Solution::countPrimes(int n) {
	if (n < 2)
		return 0;
	vector<bool> vec(n, true);

	int result = 0;
	for (int i = 2; i < n; ++i) {
		if (vec[i]) {
			++result;
			for (int j = 1; i * j < n; ++j) {
				if (vec[i * j])
					vec[i * j] = false;
			}
		}
	}
	return result;
}
