#include <Solution.h>

int getOneCnt(int v) {
	int cnt = 0;
	while (v > 0) {
		++cnt;
		v &= (v-1);
	}
	return cnt;
}

int Solution::minimumTimeRequired(vector<int>& jobs, int k) {
	sort(jobs.begin(), jobs.end());
	int size = jobs.size();
	if (size <= k) return jobs.back();

	unordered_map<int, int> state;
	state[0] = 0;
	int maxCntPer = jobs.size() - k;
	for (int i = 0 ; i < jobs.size() ; ++i) {
		auto next = state;
		for (const auto& s : state) {
			if (getOneCnt(s.first) == (maxCntPer + 1)) continue;
			next[s.first | (1 << i)] = s.second + jobs[i];
		}
		state = move(next);
	}

	unordered_map<int, int> dp = state;
	for (int i = 1 ; i < k ; ++i) {
		unordered_map<int, int> next;
		for (const auto& s : state) {
			for (const auto& v : dp) {
				if (s.first & v.first) continue;
				int idx = s.first | v.first;
				if (next.count(idx) == 0) next[idx] = INT_MAX;
				next[idx] = min(next[idx], max(s.second, v.second));
			}
		}
		dp = move(next);
	}

	return dp[(1 << size) - 1];
}
