#include <Solution.h>
#include <iostream>
#include <set>
#include <algorithm>

using std::set;
using std::max;

int getMaxKadane(vector<int>& nums) {
	int result = 0, curSum = 0;
	for (const auto& num : nums) {
		curSum = max(curSum + num, num);
		result = max(result, curSum);
	}
	return result;
}

int Solution::maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
	int result = INT_MIN;
	set<int> s;
	int m = matrix.size(), n = matrix[0].size();

	for (int i = 0 ; i < m ; ++i) {
		vector<int> nums(n, 0);
		for (int j = i ; j < m ; ++j) {
			for (int k = 0 ; k < n ; ++k) {
				nums[k] += matrix[j][k];
			}
			int kadane = getMaxKadane(nums);
			if (kadane <= k) {
				result = max(result, kadane);
				continue;
			}
			int sum = 0;
			s.clear();
			s.emplace(0);
			for (int h = 0 ; h < nums.size() ; ++h) {
				sum += nums[h];
				auto it = s.lower_bound(sum - k);
				if (it != s.end()) result = max(result, sum - *it);
				if (result == k) return k;
				s.emplace(sum);
			}
		}
	}
	return result;
}
