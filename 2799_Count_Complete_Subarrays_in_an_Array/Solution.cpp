#include <Solution.h>
#include <iostream>
#include <unordered_map>
#include <unordered_set>

int Solution::countCompleteSubarrays(vector<int>& nums) {
	unordered_set<int> us;
	for (const auto& v : nums) {
		us.emplace(v);
	}

	int l = 0;
	int result = 0;
	unordered_map<int, int> m;

	for (int i = 0 ; i < nums.size() ; ++i) {
		++m[nums[i]];

		while (l < nums.size() && m.size() == us.size()) {
			result += (nums.size() - i);

			--m[nums[l]];
			if (m[nums[l]] == 0) {
				m.erase(nums[l]);
			}
			++l;
		}
	}
	return result;
}
