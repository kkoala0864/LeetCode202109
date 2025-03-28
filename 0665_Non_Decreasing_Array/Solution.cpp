#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

bool Solution::checkPossibility(vector<int> &nums) {
	vector<int> v;

	v.emplace_back(nums[0]);

	int cnt = 0;
	for (int i = 1; i < nums.size(); ++i) {
		auto it = upper_bound(v.begin(), v.end(), nums[i]);
		if (it == v.end())
			v.emplace_back(nums[i]);
		else {
			*it = nums[i];
			++cnt;
			if (cnt > 1)
				return false;
		}
	}
	return true;
}
