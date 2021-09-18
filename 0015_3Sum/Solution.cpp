#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::sort;
using std::cout;
using std::endl;

vector<vector<int>> Solution::threeSum(vector<int>& nums) {
	vector<vector<int>> result;
	if (nums.size() < 2) return result;
	sort(nums.begin(), nums.end());

	int size = nums.size();
	for (int first(0) ; first < size ; ++first) {
		while (first > 0 && first < size && nums[first-1] == nums[first]) ++first;
		if (first == size) break;
		int left = first + 1, right = nums.size() - 1;
		int target = 0 - nums[first];
		while (left < right) {
			if (target == (nums[left] + nums[right])) {
				vector<int> tmp = {nums[first], nums[left], nums[right]};
				result.emplace_back(tmp);
				++left;
				--right;
				while (left < size && nums[left-1] == nums[left]) ++left;
				while (right >= 0 && nums[right] == nums[right+1]) --right;
			} else if (target > (nums[left] + nums[right])) {
				++left;
			} else {
				--right;
			}
		}
	}
	return result;
}
