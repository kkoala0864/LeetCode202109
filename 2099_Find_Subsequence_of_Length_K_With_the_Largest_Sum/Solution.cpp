#include <Solution.h>

vector<int> Solution::maxSubsequence(vector<int>& nums, int k) {
	vector<pair<int, int>> list;
	for (int i = 0 ; i < nums.size() ; ++i) {
		list.emplace_back(pair<int, int>(nums[i], i));
	}
	sort(list.begin(), list.end(), std::greater<>());
	vector<int> result;
	for (int i = 0 ; i < k ; ++i) {
		result.emplace_back(list[i].second);
	}
	sort(result.begin(), result.end());
	for (int i = 0 ; i < k ; ++i) {
		result[i] = nums[result[i]];
	}
	return result;
}
