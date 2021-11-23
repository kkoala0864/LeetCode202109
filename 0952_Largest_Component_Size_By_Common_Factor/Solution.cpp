#include <Solution.h>
#include <iostream>
#include <algorithm>
using std::max;
using std::cout;
using std::endl;

int getFactor(int a, int b) {
	int t = 0;
	while (a != 0 && b != 0) {
		int t = a;
		a = b % a;
		b = t;
	}
	return a == 0 ? b : a;
}

int Solution::largestComponentSize(vector<int>& nums) {
	vector<vector<int>> group;
	int result = 0;

	for (int i = 0 ; i < nums.size() ; ++i) {
		vector<int> connect;
		for (int groupIdx = 0 ; groupIdx < group.size() ; ++groupIdx) {
			for (const auto& iter : group[groupIdx]) {
				if (getFactor(iter, nums[i]) > 1) {
					connect.emplace_back(groupIdx);
					break;
				}
			}
		}
		if (connect.empty()) {
			group.push_back({nums[i]});
			result = max(result, 1);
		} else {
			for (int i = 1 ; i < connect.size() ; ++i) {
				while (!group[connect[i]].empty()) {
					group[connect[0]].emplace_back(group[connect[i]].back());
					group[connect[i]].pop_back();
				}
			}
			group[connect[0]].emplace_back(nums[i]);
			result = max(result, (int)group[connect[0]].size());
		}
	}
	return result;
}
