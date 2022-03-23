#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::sort;

vector<vector<int>> sum2(vector<int>& nums, int target, int idx) {
	int start = idx, end = nums.size() - 1;
	vector<vector<int>> result;
	while (start < end) {
		int val = nums[start] + nums[end];
		if ((val < target) || (start > idx && nums[start] == nums[start-1])) ++start;
		else if ((val > target) || (end < nums.size()-1 && nums[end] == nums[end+1])) --end;
		else result.push_back({nums[start++], nums[end--]});
	}
	return result;
}

vector<vector<int>> ksum(vector<int>& nums, int target, int idx, int size) {
	if (size == 2) return sum2(nums, target, idx);
	vector<vector<int>> result;
	for (int i = idx ; i < (nums.size() - size + 1) ; ++i) {
		vector<vector<int>> sub = ksum(nums, target - nums[i], i + 1, size - 1);
		for (auto& iter : sub) {
			iter.emplace_back(nums[i]);
			result.emplace_back(iter);
		}
		while (i < (nums.size() - size + 1) && nums[i] == nums[i+1]) ++i;
	}
	return result;
}

vector<vector<int>> Solution::fourSum2(vector<int>& nums, int target) {
	if (nums.size() < 4) return vector<vector<int>>();
	sort(nums.begin(), nums.end());
	return ksum(nums, target, 0, 4);
}
