#include <Solution.h>
#include <algorithm>

vector<int> getLPS(const string& p) {
	vector<int> lps(p.size(), 0);

	for (int i = 1 ; i < p.size() ; ++i) {
		int idx = lps[i-1];
		while (idx > 0 && p[idx] != p[i]) {
			idx = lps[idx-1];
		}
		lps[i] = idx + (p[idx] == p[i]);
	}
	return lps;
}

void kmp(vector<vector<char>>& grid, const string& p, vector<int>& lps, int m, int n, bool ishor, vector<vector<int>>& cnt) {
	vector<int> ret(m * n, 0);
	int maxColor = -1;

	ret[0] = p[0] == grid[0][0];
	if (ret[0] == p.size()) {
		++cnt[0][0];
		maxColor = 0;
	}

	for (int i = 0 ; i < m ; ++i) {
		for (int j = 0 ; j < n ; ++j) {
			int idx = i * n + j;
			if (idx == 0) continue;

			int ki = ret[idx-1];
			if (ishor) {
				while (ki > 0 && p[ki] != grid[i][j]) {
					ki = lps[ki-1];
				}
				ret[idx] = ki + (p[ki] == grid[i][j]);
			} else {
				while (ki > 0 && p[ki] != grid[j][i]) {
					ki = lps[ki-1];
				}
				ret[idx] = ki + (p[ki] == grid[j][i]);
			}
			// 0 1 2 3 4
			if (ret[idx] == p.size()) {
				int iter = max(maxColor + 1, (int)(idx - p.size() + 1));
				int end = idx;
				while (iter <= end) {
					int x = iter / n;
					int y = iter % n;
					ishor ? ++cnt[x][y] : ++cnt[y][x];
					++iter;
				}
				maxColor = end;
			}
		}
	}
}

int Solution::countCells(vector<vector<char>>& grid, string pattern) {
	int m = grid.size();
	int n = grid[0].size();
	int result = 0;

	vector<int> lps = getLPS(pattern);

	vector<vector<int>> cnt(m, vector<int>(n, 0));
	kmp(grid, pattern, lps, m, n, true, cnt);
	kmp(grid, pattern, lps, n, m, false, cnt);
	for (int i = 0 ; i < m ; ++i) {
		for (int j = 0 ; j < n ; ++j) {
			if (cnt[i][j] == 2) ++result;
		}
	}
	return result;
}
