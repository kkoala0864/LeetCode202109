#include <Solution.h>
#include <iostream>

vector<int> Solution::sumEvenAfterQueries(vector<int> &nums, vector<vector<int>> &queries) {
	int sum = 0;
	for (const auto &val : nums)
		if (!(val & 1))
			sum += val;

	vector<int> result;
	for (const auto &q : queries) {
		int oriVal = nums[q[1]];
		nums[q[1]] += q[0];
		if (!(nums[q[1]] & 1)) {
			sum += oriVal & 1 ? nums[q[1]] : q[0];
		} else {
			sum -= oriVal & 1 ? 0 : oriVal;
		}
		result.emplace_back(sum);
	}
	return result;
}
