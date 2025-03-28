#include <Solution.h>
#include <iostream>

int Solution::minOperations(vector<int> &nums) {
	int cnt = 0;
	int result = 0;

	for (const auto &v : nums) {
		if ((v + cnt) & 1)
			continue;
		++cnt;
		++result;
	}
	return result;
}
