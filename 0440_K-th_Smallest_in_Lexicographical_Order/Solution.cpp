#include <Solution.h>

long long getCnt(long long cur, long long n) {
	long long next = cur + 1;
	long long cnt = 0;

	while (cur <= n) {
		cnt += (min(n + 1LL, next) - cur);
		cur *= 10;
		next *= 10;
	}
	return cnt;
}

int Solution::findKthNumber(int n, int k) {
	long long cur = 1;
	--k;

	while (k > 0) {
		long long cnt = getCnt(cur, n);
		if (cnt <= k) {
			k -= cnt;
			++cur;
		} else {
			cur *= 10;
			--k;
		}
	}
	return cur;
}
