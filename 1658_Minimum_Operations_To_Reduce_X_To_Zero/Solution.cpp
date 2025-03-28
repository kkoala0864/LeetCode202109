#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::min;

int Solution::minOperations(vector<int> &nums, int x) {
	vector<int> l(1, 0), r(1, 0);
	int n = nums.size();
	int ls = 0, rs = 0;
	for (int i = 0; i < n; ++i) {
		ls += nums[i];
		rs += nums[n - 1 - i];

		if (ls <= x)
			l.emplace_back(ls);
		if (rs <= x)
			r.emplace_back(rs);
		if (ls > x && rs > x)
			break;
	}

	int result = INT_MAX;
	for (int i = 0; i < l.size(); ++i) {
		int rest = x - l[i];
		auto it = lower_bound(r.begin(), r.end(), rest);
		if (it != r.end() && *it == rest) {
			int local = i + (it - r.begin());
			if (local > nums.size())
				break;
			result = min(result, (int)(i + (it - r.begin())));
		}
	}
	return result == INT_MAX ? -1 : result;
}
