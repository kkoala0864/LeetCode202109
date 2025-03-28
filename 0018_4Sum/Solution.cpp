#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::sort;

vector<vector<int>> TwoSum(vector<int> &nums, int target, int start) {
	int left = start, right = nums.size() - 1;
	vector<vector<int>> result;
	while (left < right) {
		int sum = nums[left] + nums[right];
		if ((sum < target) || (left > start && nums[left] == nums[left - 1])) {
			++left;
		} else if ((sum > target) || (right < nums.size() - 1 && nums[right] == nums[right + 1])) {
			--right;
		} else {
			result.push_back({nums[left++], nums[right--]});
		}
	}
	return result;
}

vector<vector<int>> KSum(vector<int> &nums, int target, int start, int k) {
	vector<vector<int>> result;
	if (start == nums.size())
		return result;

	int averageVal = target / k;
	if ((nums[start] > averageVal) || averageVal > nums.back()) {
		return result;
	}

	if (k == 2)
		return TwoSum(nums, target, start);

	for (int i = start; i < nums.size(); ++i) {
		if (i == start || nums[i - 1] != nums[i]) {
			vector<vector<int>> tmp = KSum(nums, target - nums[i], i + 1, k - 1);
			for (auto &iter : tmp) {
				vector<int> insert = {nums[i]};
				insert.insert(insert.end(), iter.begin(), iter.end());
				result.push_back(insert);
			}
		}
	}
	return result;
}

vector<vector<int>> Solution::fourSum(vector<int> &nums, int target) {
	sort(nums.begin(), nums.end());
	return KSum(nums, target, 0, 4);
}
