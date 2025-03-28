#include <Solution.h>
#include <iostream>
#include <unordered_map>

using std::unordered_map;

long long Solution::countBadPairs(vector<int> &nums) {
	unordered_map<int, long long> m;
	long long result = 0;

	for (int i = 0; i < nums.size(); ++i) {
		result += i;
		int offset = i - nums[i];
		result -= m[offset];
		++m[offset];
	}
	return result;
}
