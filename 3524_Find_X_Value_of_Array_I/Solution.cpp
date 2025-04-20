#include <Solution.h>
#include <iostream>

// 1 2 0 1 2
// 1
vector<long long> Solution::resultArray(vector<int>& nums, int k) {
	vector<long long> cur(k, 0);
	vector<long long> result(k, 0);

	for (auto& v : nums) {
		v %= k;
		auto next = vector<long long>(k, 0);
		for (int j = 0 ; j < k ; ++j) {
			int idx = (j * v) % k;
			next[idx] += cur[j];
		}
		++next[v];
		cur = move(next);
		for (int j = 0 ; j < k ; ++j) {
			result[j] += cur[j];
		}
	}
	return result;
}
