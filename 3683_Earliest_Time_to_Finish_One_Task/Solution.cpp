#include <Solution.h>

int Solution::earliestTime(vector<vector<int>>& tasks) {
	int result = INT_MAX;
	for (const auto& t : tasks) {
		result = min(result, t[0] + t[1]);
	}
	return result;
}
