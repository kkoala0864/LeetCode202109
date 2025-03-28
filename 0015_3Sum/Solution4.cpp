#include <Solution.h>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using std::sort;
using std::unordered_map;

vector<vector<int>> Solution::threeSum4(vector<int> &nums) {
	sort(nums.begin(), nums.end());

	vector<vector<int>> result;
	for (int i = 0; i < nums.size(); ++i) {
		int target = -nums[i];
		int l = i + 1, r = nums.size() - 1;
		while (l < r) {
			int sum = nums[l] + nums[r];

			if (sum == target) {
				result.push_back({nums[i], nums[l], nums[r]});
				while (l < r - 1 && nums[l] == nums[l + 1])
					++l;
				++l;
				while (r > l + 1 && nums[r] == nums[r - 1])
					--r;
				--r;
			} else if (sum < target) {
				while (l < r - 1 && nums[l] == nums[l + 1])
					++l;
				++l;
			} else {
				while (r > l + 1 && nums[r] == nums[r - 1])
					--r;
				--r;
			}
		}
		while (i < nums.size() - 1 && nums[i] == nums[i + 1])
			++i;
	}
	return result;
}
