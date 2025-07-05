#include <Solution.h>

long long getCnt(int lx, int ly, int rx, int ry, const vector<vector<long long>>& preSum) {
	long long result = preSum[rx][ry];
	if (lx > 0) result -= preSum[lx-1][ry];
	if (ly > 0) result -= preSum[rx][ly-1];
	if (lx > 0 && ly > 0) result += preSum[lx-1][ly-1];
	return result;
}

long long dfs(int restK, int x, int y, const vector<vector<long long>>& preSum, vector<vector<vector<long long>>>& cache, const long long& mod) {
	int m = preSum.size();
	int n = preSum[0].size();

	if (x >= m || y >= n) return 0;
	if (restK == 0) {
		return getCnt(x, y, m-1, n-1, preSum) > 0 ? 1 : 0;
	}
	if (cache[restK][x][y] != -1) return cache[restK][x][y];

	cache[restK][x][y] = 0;
	for (int nx = x ; nx < m - 1 ; ++nx) {
		int cnt = getCnt(x, y, nx, n-1, preSum);
		if (cnt == 0) continue;
		cache[restK][x][y] += dfs(restK - 1, nx + 1, y, preSum, cache, mod);
		cache[restK][x][y] %= mod;
	}
	for (int ny = y ; ny < n - 1 ; ++ny) {
		int cnt = getCnt(x, y, m-1, ny, preSum);
		if (cnt == 0) continue;
		cache[restK][x][y] += dfs(restK - 1, x, ny + 1, preSum, cache, mod);
		cache[restK][x][y] %= mod;
	}
	return cache[restK][x][y];
}

int Solution::ways(vector<string>& pizza, int k) {
	int m = pizza.size();
	int n = pizza[0].size();
	long long mod = 1e9 + 7;

	vector<vector<long long>> preSum(m, vector<long long>(n, 0));
	for (int i = 0 ; i < m ; ++i) {
		for (int j = 0 ; j < n ; ++j) {
			preSum[i][j] = pizza[i][j] == 'A' ? 1 : 0;
			if (i > 0) preSum[i][j] += preSum[i-1][j];
			if (j > 0) preSum[i][j] += preSum[i][j-1];
			if (i > 0 && j > 0) preSum[i][j] -= preSum[i-1][j-1];
		}
	}

	vector<vector<vector<long long>>> cache(k, vector<vector<long long>>(m, vector<long long>(n, - 1)));

	return dfs(k-1, 0, 0, preSum, cache, mod);
}
