#include <Solution.h>

int Solution::countValidSelections(vector<int>& nums) {
	int sum = 0;
	for (const auto& v : nums) sum += v;

	int result = 0;
	int cur = 0;
	for (const auto& v : nums) {
		cur += v;
		if (v == 0) {
			if (cur == (sum - cur)) result += 2;
			else if (abs(sum - cur - cur) == 1) result += 1;
		}
	}
	return result;
}
