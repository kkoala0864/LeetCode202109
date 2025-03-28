#include <Solution.h>
#include <iostream>
#include <set>
#include <climits>
#include <algorithm>

using std::max;
using std::set;

int Solution::maxSum(vector<int> &nums) {
	set<int> st;
	for (const auto &v : nums)
		st.emplace(v);

	int sum = 0;
	int result = INT_MIN;
	for (const auto &v : st) {
		sum += v;
		result = max(result, sum);
		if (sum < 0)
			sum = 0;
	}
	return result;
}
