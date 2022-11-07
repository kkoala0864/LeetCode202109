#include <Solution.h>
#include <iostream>
#include <climits>

vector<int> Solution::majorityElement(vector<int>& nums) {
	int m1 = INT_MAX;
	int m2 = INT_MAX;
	int count1 = 0;
	int count2 = 0;

	for (const auto& iter : nums) {
		if (m1 != INT_MAX && m1 == iter) {
			++count1;
		} else if (m2 != INT_MAX && m2 == iter) {
			++count2;
		} else if (count1 == 0) {
			m1 = iter;
			count1 = 1;
		} else if (count2 == 0) {
			m2 = iter;
			count2 = 1;
		} else {
			--count1;
			--count2;
		}
	}

	count1 = 0;
	count2 = 0;
	for (const auto& iter : nums) {
		if (iter == m1) ++count1;
		if (iter == m2) ++count2;
	}
	vector<int> result;
	if (count1 > nums.size() / 3) result.emplace_back(m1);
	if (count2 > nums.size() / 3) result.emplace_back(m2);
	return result;
}
