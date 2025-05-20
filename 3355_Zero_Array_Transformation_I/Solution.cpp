#include <Solution.h>

bool Solution::isZeroArray(vector<int> &nums, vector<vector<int>> &queries) {
	vector<int> m(nums.size() + 1, 0);
	for (const auto& q : queries) {
		++m[q[0]];
		--m[q[1]+1];
	}

	int offset = 0;

	for (int i = 0 ; i < nums.size() ; ++i) {
		offset += m[i];
		if (offset < nums[i]) return false;
	}
	return true;
}
