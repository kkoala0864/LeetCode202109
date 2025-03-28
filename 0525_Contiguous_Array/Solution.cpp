#include <Solution.h>
#include <iostream>
#include <unordered_map>
using std::max;
using std::unordered_map;

int Solution::findMaxLength(vector<int> &nums) {
	int sum = 0;

	unordered_map<int, int> map;
	int result = 0;

	for (int i = 0; i < nums.size(); ++i) {
		if (nums[i])
			++sum;
		else
			--sum;

		if (0 == sum)
			result = max(result, i + 1);
		else {
			if (map.find(sum) == map.end()) {
				map[sum] = i;
			} else {
				result = max(result, i - map[sum]);
			}
		}
	}
	return result;
}
