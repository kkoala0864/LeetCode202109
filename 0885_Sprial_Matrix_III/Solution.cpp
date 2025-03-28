#include <Solution.h>
#include <iostream>
#include <unordered_map>

using std::pair;
using std::unordered_map;

vector<vector<int>> Solution::spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
	unordered_map<int, unordered_map<int, int>> visited;
	int totalSize = rows * cols;

	int x = rStart;
	int y = cStart;

	vector<vector<int>> result;
	vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
	int di = 3;
	int cnt = 0;

	while (cnt < totalSize) {
		visited[x][y] = 1;
		if (x >= 0 && y >= 0 && x < rows && y < cols) {
			++cnt;
			result.push_back({x, y});
		}

		int tdi = (di + 1) % 4;
		int tx = x + dir[tdi].first;
		int ty = y + dir[tdi].second;
		if (visited[tx][ty] == 1) {
			x += dir[di].first;
			y += dir[di].second;
		} else {
			di = tdi;
			x = tx;
			y = ty;
		}
	}
	return result;
}
