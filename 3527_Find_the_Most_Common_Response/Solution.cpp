#include <Solution.h>

string Solution::findCommonResponse(vector<vector<string>>& responses) {
	unordered_map<string, int> cnt;

	for (const auto& r : responses) {
		unordered_set<string> dedup;
		for (const auto& s : r) {
			if (dedup.count(s)) continue;
			++cnt[s];
			dedup.emplace(s);
		}
	}

	string result;
	int maxCnt = 0;

	for (const auto& e : cnt) {
		if (e.second > maxCnt) {
			maxCnt = e.second;
			result = e.first;
		} else if (e.second == maxCnt) {
			result = min(result, e.first);
		}
	}
	return result;
}
