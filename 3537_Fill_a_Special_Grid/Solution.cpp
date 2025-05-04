#include <Solution.h>

void dfs(int x, int y, int size, int& value, vector<vector<int>>& result) {
	if (size == 1) {
		result[x][y] = value++;
		return;
	}

	int hs = size / 2;
	dfs(x, y + hs, hs, value, result);
	dfs(x + hs, y + hs, hs, value, result);
	dfs(x + hs, y, hs, value, result);
	dfs(x, y, hs, value, result);
}

vector<vector<int>> Solution::specialGrid(int N) {
	int size = 1 << N;
	vector<vector<int>> result(size, vector<int>(size, 0));
	int value = 0;
	dfs(0, 0, size, value, result);
	return result;
}
