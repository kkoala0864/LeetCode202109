#include <Solution.h>

int Solution::largestUniqueNumber(vector<int> &nums) {
	unordered_map<int, int> cnt;
	for (const auto& v : nums) ++cnt[v];

	int result = -1;
	for (const auto& e : cnt) {
		if (e.second == 1) {
			result = max(result, e.first);
		}
	}
	return result;
}
