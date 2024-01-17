#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;
int getCnt(int v, int mask) {
	int mv = v & mask;
	int result = 0;
	while (mv) {
		++result;
		mv &= (mv - 1);
	}
	return result;
}

long long Solution::findMaximumNumber(long long k, int x) {
	long long cnt = 0;
	int mask = 0;
	for (int i = x ; i <= 32 ; i += x) {
		mask = mask | (1 << (i - 1));
	}
	int curV = 0;
	while (cnt < k) {
		++curV;
		cnt += getCnt(curV, mask);
	}
	return cnt == k ? curV : curV - 1;

}
