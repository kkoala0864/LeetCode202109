#include <Solution.h>

bool check(int n) {
	vector<int> cnt(10, 0);
	while (n > 0) {
		++cnt[n % 10];
		n /= 10;
	}
	if (cnt[0] != 0) return false;
	for (int i = 1 ; i < 10 ; ++i) {
		if (cnt[i] == 0) continue;
		if (cnt[i] != i) return false;
	}
	return true;
}

int Solution::nextBeautifulNumber(int n) {
	int size = 0;
	int limit = 1;
	int tmp = n;
	while (tmp > 0) {
		++size;
		tmp /= 10;
		limit *= 10;
	}

	for (int i = n + 1 ; i < limit ; ++i) {
		if (check(i)) return i;
	}

	for (int i = limit ; i < (limit * 10) ; ++i) {
		if (check(i)) return i;
	}
	return -1;
}


