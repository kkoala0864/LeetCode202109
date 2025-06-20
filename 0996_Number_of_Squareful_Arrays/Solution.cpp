#include <Solution.h>
#include <cmath>

bool check(long long a, long long b) {
	int sq = sqrt(a + b);
	return sq * sq == a + b;
}

long long dfs(int idx, int size, int pv, unordered_map<int, vector<int>>& cnt, int mask, unordered_map<int, unordered_map<int, int>>& cache) {
	if (idx == size) return 1;
	if (cache.count(pv) && cache[pv].count(mask)) return cache[pv][mask];

	long long cur = 0;
	for (auto& e : cnt) {
		if (e.second.empty() || !check(e.first, pv)) continue;
		int i = e.second.back();
		e.second.pop_back();
		cur += dfs(idx + 1, size, e.first, cnt, mask | (1 << i), cache);
		e.second.emplace_back(i);
	}
	return cache[pv][mask] = cur;
}

int Solution::numSquarefulPerms(vector<int>& nums) {
	unordered_map<int, vector<int>> cnt;
	unordered_map<int, unordered_map<int, int>> cache;
	int size = nums.size();

	long long result = 0;
	for (int i = 0 ; i < nums.size() ; ++i) {
		cnt[nums[i]].emplace_back(i);
	}
	for (auto& v : cnt) {
		int idx = v.second.back();
		v.second.pop_back();
		result += dfs(1, size, v.first, cnt, (1 << idx), cache);
		v.second.emplace_back(idx);
	}

	return result;
}
