#include <Solution.h>
#include <iostream>

vector<int> Solution::countBits2(int n) {
	vector<int> result(n+1, 0);
	for (int i = 1 ; i <= n ; ++i) {
		result[i] = result[i>>1] + (i % 2);
	}
	return result;
}

