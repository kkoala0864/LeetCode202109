#include <Solution.h>
#include <iostream>
#include <unordered_map>

using std::unordered_map;

bool Solution::isPossible(vector<int>& nums) {
	unordered_map<int, int> cnt, end;

	for (const auto& v : nums) ++cnt[v];

	for (const auto& v : nums) {
		if (cnt[v] == 0) continue;
		--cnt[v];

		if (end[v-1] > 0) {
			--end[v-1];
			++end[v];
		} else if (cnt[v+1] > 0 && cnt[v+2] > 0) {
			--cnt[v+1];
			--cnt[v+2];
			++end[v+2];
		} else {
			return false;
		}
	}
	return true;
}
