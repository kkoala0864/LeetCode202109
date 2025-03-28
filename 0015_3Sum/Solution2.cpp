#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::sort;

vector<vector<int>> Solution::threeSum2(vector<int> &nums) {
	vector<vector<int>> result;
	sort(nums.begin(), nums.end());
	for (int i = 0; i < nums.size(); ++i) {
		int start = i + 1, end = nums.size() - 1;
		int restOfNo = -nums[i];
		while (start < end) {
			int sum = nums[start] + nums[end];
			if (sum == restOfNo) {
				vector<int> insert = {nums[i], nums[start], nums[end]};
				result.push_back(insert);
				while (start < end && nums[start] == nums[start + 1])
					++start;
				while (end > start && nums[end] == nums[end - 1])
					--end;
				++start;
				--end;
			} else if (sum < restOfNo) {
				while (start < end && nums[start] == nums[start + 1])
					++start;
				++start;
			} else {
				while (end > start && nums[end] == nums[end - 1])
					--end;
				--end;
			}
		}
		while (i < nums.size() - 1 && nums[i] == nums[i + 1])
			++i;
	}
	return result;
}
