#include <Solution.h>
#include <iostream>

vector<vector<int>> Solution::findMatrix(vector<int>& nums) {
	vector<int> m(201, 0);

	vector<vector<int>> result;
	for (int i = 0 ; i < nums.size() ; ++i) {
		int idx = m[nums[i]];

		if (result.size() < (idx + 1)) {
			result.emplace_back(vector<int>());
		}
		result[idx].emplace_back(nums[i]);
		++m[nums[i]];
	}
	return result;
}
