#include <Solution.h>

// n = 5, m = 4, k = 3,
//
// [0 1 2 3 4] choose k location for increasing sequence, and rest of location should assign value which small than max Value;
// 1. choose k element from m element
// 2. choose n location to put k element
// 3. assign rest of location value which is small than maximum value
// 4. each assign can't be larger than next increaing number

// dfs with memorize
// 0 1 2 3 4

// dp[curVal][k]
int Solution::numOfArrays(int n, int m, int k) {
	if (m < k) return 0;
	long long mod = 1e9 + 7;
	vector<vector<long long>> dp(m + 1, vector<long long>(k + 1, 0));
	for (int i = 1 ; i <= m ; ++i) {
		dp[i][1] = 1;
	}
	for (int i = 2 ; i <= n ; ++i) {
		auto next = vector<vector<long long>>(m + 1, vector<long long>(k + 1, 0));
		for (int mi = 1 ; mi <= m ; ++mi) {
			for (int mj = mi ; mj <= m ; ++mj) {
				for (int ki = 1 ; ki <= k ; ++ki) {
					if (mi == mj) {
						next[mi][ki] += ((long long)mi * dp[mi][ki]);
						next[mi][ki] %= mod;
					} else if (mi < mj) {
						if ((ki + 1) > k) continue;
						next[mj][ki+1] += (dp[mi][ki]);
						next[mj][ki+1] %= mod;

					}
				}
			}
		}
		dp = std::move(next);
	}
	long long result = 0;
	for (int i = 1 ; i <= m ; ++i) {
		result += dp[i][k];
		result %= mod;
	}
	return result;
}

/*
long long dfs(int idx, int n, int cm, int m, int k, long long mod, unordered_map<int, unordered_map<int, unordered_map<int, long long>>>& cache) {
	if (idx == n) {
		return k == 0;
	}
	if (cache.count(idx) && cache[idx].count(cm) && cache[idx][cm].count(k)) return cache[idx][cm][k];

	long long cur = 0;
	for (int i = 1 ; i <= cm ; ++i) {
		cur += dfs(idx + 1, n, cm, m, k, mod, cache);
		cur %= mod;
	}
	for (int i = cm + 1 ; i <= (m - k + 1) ; ++i) {
		cur += dfs(idx + 1, n, i, m, k - 1, mod, cache);
		cur %= mod;
	}
	return cache[idx][cm][k] = cur;
}

int Solution::numOfArrays(int n, int m, int k) {
	if (m < k) return 0;
	long long mod = 1e9 + 7;
	long long cur = 0;
	unordered_map<int, unordered_map<int, unordered_map<int, long long>>> cache;
	for (int i = 1 ; i <= (m - k + 1) ; ++i) {
		cur += dfs(1, n, i, m, k-1, mod, cache);
		cur %= mod;
	}
	return cur;
}
*/
