#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::max;

vector<int> Solution::findDiagonalOrder(vector<vector<int>>& nums) {
	int ySize = 0;
	for (const auto& v : nums) {
		ySize = max(ySize, (int)v.size());
	}
	vector<vector<int>> m(nums.size() + ySize, vector<int>());
	vector<int> result;

	for (int i = nums.size() - 1 ; i >= 0 ; --i) {
		for (int j = 0 ; j < nums[i].size() ; ++j) {
			m[i + j].emplace_back(nums[i][j]);
		}
	}

	for (int i = 0 ; i < m.size() ; ++i) {
		for (const auto& v : m[i]) {
			result.emplace_back(v);
		}
	}
	return result;
}
