#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::upper_bound;

int Solution::chalkReplacer(vector<int> &chalk, int k) {
	vector<long long> preSum;

	long long sum = 0;
	for (const auto &c : chalk) {
		sum += (long long)c;
		preSum.emplace_back(sum);
	}
	k %= sum;

	int idx = upper_bound(preSum.begin(), preSum.end(), k) - preSum.begin();
	return idx;
}
