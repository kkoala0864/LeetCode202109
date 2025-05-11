#include <Solution.h>

int Solution::minDeletion(string s, int k) {
	vector<int> cnt(26, 0);
	for (const auto& c : s) ++cnt[c-'a'];

	priority_queue<int, vector<int>, greater<>> pq;
	int result = 0;
	for (const auto &v : cnt) {
		if (v == 0) continue;
		pq.emplace(v);
	}
	while (pq.size() > k) {
		result += pq.top();
		pq.pop();
	}
	return result;
}
