#include <Solution.h>

int Solution::minimumDeletions(string word, int k) {
	vector<int> cnt(26, 0);
	for (const auto& c : word) ++cnt[c-'a'];

	map<int, int> cm;
	for (const auto& v : cnt) {
		if (v == 0) continue;
		++cm[v];
	}
	map<int, pair<int, int>> post;
	int fCnt = 0;
	int sum = 0;
	for (auto iter = cm.rbegin() ; iter != cm.rend() ; ++iter) {
		fCnt += iter->second;
		sum += (iter->first * iter->second);
		post[iter->first] = pair<int, int>(fCnt, sum);
	}

	int result = INT_MAX;
	int lastCost = 0;
	for (const auto& c : cm) {
		int cur = 0;
		auto postIter = post.upper_bound(c.first + k);
		if (postIter != post.end()) {
			int targetV = c.first + k;
			cur += (postIter->second.second - (postIter->second.first * targetV));
		}
		result = min(result, lastCost + cur);
		lastCost += (c.first * c.second);
	}
	return result;
}
