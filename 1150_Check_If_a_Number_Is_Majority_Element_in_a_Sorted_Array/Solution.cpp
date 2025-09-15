#include <Solution.h>

bool Solution::isMajorityElement(vector<int>& nums, int target) {
	int sidx = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
	int eidx = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
	return (eidx - sidx) > (nums.size() / 2);
}
