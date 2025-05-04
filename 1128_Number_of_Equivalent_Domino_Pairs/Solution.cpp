#include <Solution.h>

int Solution::numEquivDominoPairs(vector<vector<int>>& dominoes) {
	vector<vector<int>> preSum(10, vector<int>(10, 0));
	int result = 0;

	for (const auto& d : dominoes) {
		if (d[0] == d[1]) {
			result += preSum[d[0]][d[1]];
		} else {
			result += (preSum[d[0]][d[1]] + preSum[d[1]][d[0]]);
		}
		++preSum[d[0]][d[1]];
	}
	return result;

}
