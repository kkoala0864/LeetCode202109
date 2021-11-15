#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::sort;

vector<int> Solution::largestDivisibleSubset(vector<int>& nums) {
	sort(nums.begin(), nums.end());
	vector<vector<int>> set(nums.size(), vector<int>());
	int maxSize = 0;
	int maxIdx = -1;
	for (int i = 0 ; i < nums.size() ; ++i) {
		for (int j = i - 1 ; j >= 0 ; --j) {
			if (nums[i] % nums[j] == 0) {
				if (set[j].size() > set[i].size()) {
					set[i] = set[j];
				}
			}
		}
		set[i].emplace_back(nums[i]);
		if (set[i].size() > maxSize) {
			maxSize = set[i].size();
			maxIdx = i;
		}
	}
	return set[maxIdx];
}
