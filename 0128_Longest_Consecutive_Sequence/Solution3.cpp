#include <Solution.h>
#include <iostream>
#include <unordered_set>
#include <algorithm>

using std::unordered_set;
using std::max;

int Solution::longestConsecutive3(vector<int>& nums) {
	unordered_set<int> map;
	int result = 0;
	for (const auto& iter : nums) map.emplace(iter);

	for (const auto& iter : map) {
		if (map.find(iter-1) == map.end()) {
			int cnt = 0;
			while (map.find(iter+cnt) != map.end()) ++cnt;
			result = max(result, cnt);
		}
	}
	return result;
}
