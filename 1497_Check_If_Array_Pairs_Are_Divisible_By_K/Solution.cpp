#include <Solution.h>
#include <iostream>

bool Solution::canArrange(vector<int> &arr, int k) {
	vector<int> cnt(k, 0);
	for (const auto &v : arr) {
		++cnt[((v % k) + k) % k];
	}

	for (int i = 0; i <= (k / 2); ++i) {
		int op = (k - i) % k;
		if (op != i) {
			if (cnt[op] == cnt[i]) {
				continue;
			} else {
				return false;
			}
		} else {
			if (cnt[i] % 2 == 1)
				return false;
		}
	}
	return true;
}
