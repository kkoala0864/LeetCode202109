#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

char Solution::findKthBit(int n, int k) {
	int flipCnt = 0;
	--n;

	while (n > 0) {
		int base = pow(2, n);
		if (k == base) return flipCnt > 0 ? '0' : '1';
		if (k > base) {
			flipCnt ^= 1;
			k -= base;
			k = base - k;
		}
		--n;
	}

	return flipCnt > 0 ? '1' : '0';
}
