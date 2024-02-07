#include <Solution.h>
#include <iostream>
#include <unordered_set>

using std::unordered_set;

vector<vector<int>> Solution::findDifference(vector<int>& nums1, vector<int>& nums2) {
	unordered_set<int> s1, s2;
	for (const auto& v : nums1) s1.emplace(v);
	for (const auto& v : nums2) s2.emplace(v);

	vector<vector<int>> result(2, vector<int>());

	for (const auto& v : s1) {
		if (s2.count(v) == 0) result[0].emplace_back(v);
	}
	for (const auto& v : s2) {
		if (s1.count(v) == 0) result[1].emplace_back(v);
	}
	return result;
}
