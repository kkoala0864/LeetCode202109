#include <Solution.h>
#include <iostream>
#include <unordered_set>

using std::unordered_set;

bool Solution::sequenceReconstruction(vector<int> &nums, vector<vector<int>> &sequences) {
	vector<unordered_set<int>> od(nums.size() + 1, unordered_set<int>());

	for (const auto &s : sequences) {
		for (int i = 1; i < s.size(); ++i) {
			if (s[i] > nums.size() || s[i - 1] > nums.size())
				return false;
			od[s[i - 1]].emplace(s[i]);
		}
	}

	int cur = nums[0];
	for (int i = 1; i < nums.size(); ++i) {
		if (!od[cur].count(nums[i]))
			return false;
		cur = nums[i];
	}

	return true;
}
