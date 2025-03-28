#include <Solution.h>
#include <iostream>
#include <unordered_map>

using std::unordered_map;

vector<int> Solution::nextGreaterElement2(vector<int> &nums1, vector<int> &nums2) {
	vector<int> st;
	unordered_map<int, int> uMap;
	for (int i = 0; i < nums2.size(); ++i) {
		while (!st.empty() && nums2[i] > nums2[st.back()]) {
			uMap[nums2[st.back()]] = nums2[i];
			st.pop_back();
		}
		st.emplace_back(i);
	}

	vector<int> result;
	for (const auto &iter : nums1) {
		if (uMap.find(iter) == uMap.end()) {
			result.emplace_back(-1);
		} else {
			result.emplace_back(uMap[iter]);
		}
	}
	return result;
}
