#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

long long Solution::minEnd(int n, int x) {
	if (n == 1) return x;
	long long result = x;
	long long nVal = n-1;
	long long nIdx = 0;

	for (int i = 0 ; i < 64 ; ++i) {
		if ((((long long)x >> i) & 1) == 1) continue;
		if (((nVal >> nIdx) & 1) == 1) {
			result = result | ((long long)1 << i);
		}
		++nIdx;
	}
	return result;
}
