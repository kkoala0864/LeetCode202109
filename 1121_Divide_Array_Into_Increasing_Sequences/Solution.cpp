#include <Solution.h>

bool Solution::canDivideIntoSubsequences(vector<int>& nums, int k) {
	int size = nums.size();
	int per = size / k;

	unordered_map<int, int> cnt;
	for (const auto& v : nums) {
		++cnt[v];
		if (cnt[v] > per) return false;
	}
	return true;
}
