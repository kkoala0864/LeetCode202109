#include <Solution.h>
#include <iostream>
#include <vector>

using std::vector;

void dfs(int row, int n, vector<int> &rows, int &result) {
	if (row == n) {
		++result;
		return;
	}

	for (int col = 0; col < n; ++col) {
		int idx = 0;
		for (; idx < rows.size(); ++idx) {
			if (rows[idx] == col)
				break;
			if (abs(rows[idx] - col) == abs(idx - row))
				break;
		}
		if (idx != row)
			continue;
		rows.emplace_back(col);
		dfs(row + 1, n, rows, result);
		rows.pop_back();
	}
}

int Solution::totalNQueens(int n) {
	vector<int> rows;
	int result = 0;
	dfs(0, n, rows, result);
	return result;
}
