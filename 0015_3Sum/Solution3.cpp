#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::sort;

vector<vector<int>> Solution::threeSum3(vector<int> &nums) {
	vector<vector<int>> result;
	if (nums.size() < 3)
		return result;

	sort(nums.begin(), nums.end());
	for (int i = 0; i < nums.size(); ++i) {
		int rest = -nums[i];
		int start = i + 1;
		int end = nums.size() - 1;
		while (start < end) {
			int sum = nums[start] + nums[end];
			if (sum == rest) {
				result.push_back({nums[i], nums[start], nums[end]});
				while (start < end && nums[start] == nums[start + 1])
					++start;
				++start;
				while (start < end && nums[end] == nums[end - 1])
					--end;
				--end;
			} else if (sum < rest) {
				while (start < end && nums[start] == nums[start + 1])
					++start;
				++start;
			} else {
				while (start < end && nums[end] == nums[end - 1])
					--end;
				--end;
			}
		}
		while (i < nums.size() - 1 && nums[i] == nums[i + 1])
			++i;
	}
	return result;
}
