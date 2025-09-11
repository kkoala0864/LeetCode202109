#include <Solution.h>

int Solution::peopleAwareOfSecret(int n, int delay, int forget) {
	long long mod = 1e9 + 7;

	vector<long long> list(n, 0);
	list[0] = 1;

	for (int i = 1 ; i < n ; ++i) {
		if (i < delay) continue;
		for (int j = max(0, i - forget + 1) ; j <= (i - delay) ; ++j) {
			list[i] += list[j];
			list[i] %= mod;
		}
	}
	long long result = 0;
	for (int i = n - 1 ; i >= (n - forget) ; --i) {
		result += list[i];
		result %= mod;
	}
	return result;
}
