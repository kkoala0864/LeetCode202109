#include <Solution.h>

int Solution::lengthOfLIS(vector<int> &nums) {
	vector<int> list;

	for (const auto& c : nums) {
		int idx = lower_bound(list.begin(), list.end(), c) - list.begin();
		if (idx == list.size()) {
			list.emplace_back(c);
		} else {
			list[idx] = c;
		}
	}
	return list.size();
}
