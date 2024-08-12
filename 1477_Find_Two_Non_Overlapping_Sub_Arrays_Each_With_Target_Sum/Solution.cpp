#include <Solution.h>
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <climits>

using std::unordered_map;
using std::min;

int Solution::minSumOfLengths(vector<int>& arr, int target) {
	unordered_map<int, int> idx;
	vector<int> dp;

	int result = INT_MAX;
	int sum = 0;
	int curMin = INT_MAX;
	for (int i = 0 ; i < arr.size() ; ++i) {
		sum += arr[i];
		if (sum == target) {
			curMin = min(curMin, i + 1);
		}
		if (idx.count(sum - target)) {
			curMin = min(curMin, i - idx[sum-target]);
			if (dp[idx[sum-target]] != INT_MAX) {
				result = min(result, i - idx[sum-target] + dp[idx[sum-target]]);
			}
		}
		dp.emplace_back(curMin);
		idx[sum] = i;
	}
	return result == INT_MAX ? -1 : result;
}
