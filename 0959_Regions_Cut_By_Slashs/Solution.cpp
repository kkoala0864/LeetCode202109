#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::min;

int find(vector<int>& root, int idx) {
	if (root[idx] == idx) return idx;
	return root[idx] = find(root, root[idx]);
}

void uni(vector<int>& root, int lhs, int rhs, int& cnt) {
	int lr = find(root, lhs);
	int rr = find(root, rhs);
	if (lr == rr) return;
	--cnt;
	root[lr] = root[rr] = min(lr, rr);
}

int getRoot(vector<vector<vector<int>>>& root, vector<string>& grid, int i, int j, int dir) {
	if (grid[i][j] == ' ') return root[i][j][0];
	else if (grid[i][j] == '\\') {
		if (dir == 0 || dir == 1) return root[i][j][0];
		else return root[i][j][1];
	} else {
		if (dir == 0 || dir == 3) return root[i][j][0];
		else return root[i][j][1];
	}
}

int Solution::regionsBySlashes(vector<string>& grid) {
	int n = grid.size();
	vector<vector<vector<int>>> gridRoot(n, vector<vector<int>>(n, vector<int>(4, -1)));
	int cnt = 0;
	for (int i = 0 ; i < n ; ++i) {
		for (int j = 0 ; j < n ; ++j) {
			if (grid[i][j] == ' ') {
				gridRoot[i][j][0] = gridRoot[i][j][1] = cnt;
				++cnt;
			} else {
				gridRoot[i][j][0] = cnt;
				gridRoot[i][j][1] = cnt + 1;
				cnt += 2;
			}
		}
	}

	vector<int> root;
	for (int i = 0 ; i < cnt ; ++i) root.emplace_back(i);
	for (int i = 0 ; i < n ; ++i) {
		for (int j = 0 ; j < n ; ++j) {
			if (j < n - 1) {
				int curR = getRoot(gridRoot, grid, i, j, 1);
				int left = getRoot(gridRoot, grid, i, j + 1, 3);
				uni(root, curR, left, cnt);
			}
			if (i < n - 1) {
				int curD = getRoot(gridRoot, grid, i, j, 2);
				int up = getRoot(gridRoot, grid, i + 1, j, 0);
				uni(root, curD, up, cnt);
			}
		}
	}
	return cnt;
}
