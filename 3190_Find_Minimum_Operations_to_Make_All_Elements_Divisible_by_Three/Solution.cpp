#include <Solution.h>

int Solution::minimumOperations(vector<int>& nums) {
	int result = 0;

	for (const auto& v : nums) {
		int m = v % 3;
		result += min(m, 3 - m);
	}
	return result;
}
