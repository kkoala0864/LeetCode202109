#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::sort;
using std::cout;
using std::endl;

vector<vector<int>> Solution::divideArray(vector<int>& nums, int k) {
	sort(nums.begin(), nums.end());

	vector<vector<int>> result;
	for (int i = 0 ; i < nums.size() ; ++i) {
		int mod = i % 3;
		if (mod == 0) {
			result.emplace_back(vector<int>());
			result.back().emplace_back(nums[i]);
		} else if (mod == 1 && ((nums[i] - nums[i-1]) <= k) || mod == 2 && ((nums[i] - nums[i-2]) <= k)) {
			result.back().emplace_back(nums[i]);
		} else {
			return vector<vector<int>>();
		}
	}
	return result;
}
