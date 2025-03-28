#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::min;

bool Solution::lemonadeChange(vector<int> &bills) {
	int sum = 0;
	vector<int> price = {20, 10, 5};
	vector<int> cnt(3, 0);

	for (auto &b : bills) {
		int diff = b - 5;
		if (diff > sum)
			return false;

		for (int i = 0; i < 3; ++i) {
			int v = min(cnt[i], diff / price[i]);
			diff -= (v * price[i]);
			cnt[i] -= v;
		}
		if (diff != 0)
			return false;
		for (int i = 0; i < 3; ++i) {
			int v = b / price[i];
			cnt[i] += v;
			b -= (price[i] * v);
		}
		sum += 5;
	}
	return true;
}
