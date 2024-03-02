#include <Solution.h>
#include <iostream>

vector<int> Solution::sortedSquares(vector<int>& nums) {
	vector<int> st;
	int assing_idx = 0;
	for (const auto& v : nums) {
		if (v < 0) {
			st.emplace_back(v);
		} else {
			while (!st.empty() && abs(st.back()) < v) {
				nums[assing_idx++] = st.back() * st.back();
				st.pop_back();
			}
			nums[assing_idx++] = v * v;
		}
	}
	while (!st.empty()) {
		nums[assing_idx++] = st.back() * st.back();
		st.pop_back();
	}
	return nums;
}
