#include <Solution.h>

bool Solution::partitionArray(vector<int>& nums, int k) {
	if (nums.size() % k) return false;

	int gCnt = nums.size() / k;
	unordered_map<int, int> cnt;
	for (const auto& v : nums) {
		++cnt[v];
		if (cnt[v] > gCnt) return false;
	}
	return true;
}
