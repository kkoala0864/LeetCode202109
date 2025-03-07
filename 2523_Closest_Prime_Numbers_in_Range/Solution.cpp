#include <Solution.h>
#include <iostream>
#include <climits>

using std::cout;
using std::endl;

vector<int> Solution::closestPrimes(int left, int right) {
	vector<bool> isPrime(right + 1, true);
	isPrime[0] = false;
	isPrime[1] = false;
	isPrime[2] = true;

	for (int i = 2 ; (i * i) <= right ; ++i) {
		if (isPrime[i]) {
			for (int j = i * i ; j <= right ; j += i) {
				isPrime[j] = false;
			}
		}
	}

	int last = -1;
	vector<int> result = {-1, -1};
	int minV = INT_MAX;
	for (int i = left ; i <= right ; ++i) {
		if (isPrime[i]) {
			if (last != -1) {
				if (minV > (i - last)) {
					result = {last, i};
					minV = i - last;
				}
			}
			last = i;
		}
	}
	return result;
}
