#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::max;
using std::min;

int dfs(const vector<int>& arr, vector<int>& cache, int cur, int k) {
	if (cur >= arr.size()) return 0;
	if (cache[cur] != 0) return cache[cur];

	int result = 0;
	int curMax = 0;
	int v = 0;

	for (int i = cur ; i < min(cur + k, (int) arr.size()) ; ++i) {
		curMax = max(curMax, arr[i]);
		v = max(v, curMax * (i - cur + 1));
		result = max(v + dfs(arr, cache, i + 1, k), result);
	}
	cache[cur] = result;
	return result;
}

int Solution::maxSumAfterPartitioning(vector<int>& arr, int k) {
	int size = arr.size();
	vector<int> dp(size, 0);
	return dfs(arr, dp, 0, k);
}
