#include <Solution.h>
#include <iostream>
#include <unordered_set>
#include <algorithm>

using std::max;
using std::unordered_set;

int Solution::findMaxK(vector<int> &nums) {
	unordered_set<int> us;

	int result = 0;
	for (const auto &v : nums) {
		if (us.count(-v)) {
			result = max(result, abs(v));
		}
		us.emplace(v);
	}
	return result == 0 ? -1 : result;
}
