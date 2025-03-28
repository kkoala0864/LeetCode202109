#include <Solution.h>
#include <iostream>
#include <unordered_map>

using std::unordered_map;

int Solution::minOperations(vector<int> &nums) {
	unordered_map<int, int> m;
	for (const auto &v : nums)
		++m[v];

	int result = 0;
	for (const auto &e : m) {
		if (e.second == 1)
			return -1;
		if (e.second == 2)
			++result;
		else {
			result += (e.second / 3);
			if (e.second % 3 != 0)
				++result;
		}
	}
	return result;
}
