#include <Solution.h>
#include <iostream>
#include <unordered_map>
#include <algorithm>

using std::max;
using std::unordered_map;

int Solution::longestConsecutive(vector<int> &nums) {
	unordered_map<int, bool> uMap;
	for (const auto &iter : nums)
		uMap[iter] = true;

	int result = 0;
	for (const auto &iter : uMap) {
		if (uMap.find(iter.first - 1) == uMap.end()) {
			int idx = iter.first;
			while (uMap[idx + 1])
				++idx;
			result = max(result, idx - iter.first + 1);
		}
	}
	return result;
}
