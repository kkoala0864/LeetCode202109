#include <Solution.h>
#include <iostream>
#include <unordered_map>

using std::unordered_map;

int Solution::maxOperations(vector<int>& nums, int k) {
	unordered_map<int, int> cnt;
	int result = 0;
	for (auto& iter : nums) {
		if (cnt[k-iter] > 0) {
			++result;
			--cnt[k-iter];
		} else {
			++cnt[iter];
		}
	}
	return result;
}

