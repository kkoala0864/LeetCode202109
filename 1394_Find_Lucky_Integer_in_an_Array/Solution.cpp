#include <Solution.h>

int Solution::findLucky(vector<int>& arr) {
	unordered_map<int, int> cnt;
	for (const auto& v : arr) ++cnt[v];
	int result = INT_MIN;
	for (const auto& e : cnt) {
		if (e.first == e.second) {
			result = max(result, e.first);
		}
	}
	return result == INT_MIN ? -1 : result;
}
