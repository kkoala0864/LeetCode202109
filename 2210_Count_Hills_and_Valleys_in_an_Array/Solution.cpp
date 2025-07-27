#include <Solution.h>

int Solution::countHillValley(vector<int>& nums) {
	vector<int> tmp;
	for (int i = 0 ; i < nums.size() ; ++i) {
		if (tmp.empty() || tmp.back() != nums[i]) tmp.emplace_back(nums[i]);
	}
	nums = std::move(tmp);
	int size = nums.size();
	int result = 0;

	for (int i = 1 ; i < size - 1 ; ++i) {
		int l = i - 1, r = i + 1;
		while (l >= 0 && nums[l] == nums[i]) {
			--l;
		}
		while (r < size && nums[r] == nums[i]) {
			++r;
		}
		if (l < 0 || r == size) continue;
		if ((nums[l] < nums[i] && nums[r] < nums[i]) ||
		    (nums[l] > nums[i] && nums[r] > nums[i])) ++result;
	}
	return result;
}
