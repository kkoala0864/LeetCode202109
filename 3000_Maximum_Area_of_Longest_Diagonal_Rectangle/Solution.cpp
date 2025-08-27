#include <Solution.h>

int Solution::areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
	int maxDisLen = 0;
	int result = 0;
	for (const auto& d : dimensions) {
		int cur = d[0] * d[0] + d[1] * d[1];
		if (cur > maxDisLen) {
			result = d[0] * d[1];
			maxDisLen = cur;
		} else if (cur == maxDisLen) {
			result = max(result, d[0] * d[1]);
		}
	}
	return result;
}
