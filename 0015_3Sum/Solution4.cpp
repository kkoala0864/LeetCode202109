#include <Solution.h>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using std::sort;
using std::unordered_map;

vector<vector<int>> Solution::threeSum4(vector<int>& nums) {
	int n = nums.size();
	vector<vector<int>> result;
	sort(nums.begin(), nums.end());

	for (int i = 0 ; i < n ; ++i) {
		int target = -nums[i];
		int left = i + 1, right = n - 1;
		while (left < right) {
			int val = nums[left] + nums[right];
			if (val == target) {
				result.push_back({nums[i], nums[left], nums[right]});
				while (left < n - 1 && nums[left] == nums[left+1]) ++left;
				++left;
				while (right > 0 && nums[right] == nums[right-1]) --right;
				--right;
			} else if (val < target) {
				while (left < n - 1 && nums[left] == nums[left+1]) ++left;
				++left;
			} else {
				while (right > 0 && nums[right] == nums[right-1]) --right;
				--right;
			}
		}
		while (i < n - 1 && nums[i] == nums[i+1]) ++i;
	}
	return result;
}
