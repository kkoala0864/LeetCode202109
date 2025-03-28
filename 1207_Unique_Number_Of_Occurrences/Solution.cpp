#include <Solution.h>
#include <iostream>
#include <unordered_map>
#include <unordered_set>

using std::unordered_map;
using std::unordered_set;

bool Solution::uniqueOccurrences(vector<int> &arr) {
	unordered_map<int, int> cnt;
	for (const auto &v : arr)
		++cnt[v];
	unordered_set<int> us;

	for (const auto &e : cnt) {
		if (us.count(e.second))
			return false;
		us.emplace(e.second);
	}
	return true;
}
