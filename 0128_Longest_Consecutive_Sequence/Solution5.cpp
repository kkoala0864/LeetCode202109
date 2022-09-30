#include <Solution.h>
#include <iostream>
#include <unordered_set>
#include <algorithm>

using std::unordered_set;
using std::max;

int Solution::longestConsecutive5(vector<int>& nums) {
	unordered_set<int> uSet;
	int result = 0;

	for (const auto& v : nums) uSet.emplace(v);
	for (const auto& v : uSet) {
		if (uSet.find(v-1) == uSet.end()) {
			int cnt = 0;
			for (int i = v ; uSet.find(i) != uSet.end() ; ++i) {
				++cnt;
			}
			result = max(result, cnt);
		}
	}
	return result;
}
