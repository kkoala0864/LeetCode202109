#include <Solution.h>
#include <iostream>
#include <queue>
#include <climits>

using std::cout;
using std::endl;
using std::pair;
using std::queue;

int Solution::shortestPathBinaryMatrix2(vector<vector<int>> &grid) {
	if (grid[0][0] == 1)
		return -1;
	vector<vector<int>> cnt(grid.size(), vector<int>(grid[0].size(), INT_MAX));
	cnt[0][0] = 1;

	vector<int> axis = {1, 0, -1, 0, 1, -1, -1, 1, 1};
	queue<pair<int, int>> que;
	que.emplace(pair<int, int>(0, 0));

	while (!que.empty()) {
		int x = que.front().first;
		int y = que.front().second;
		que.pop();

		for (int i = 0; i < 8; ++i) {
			int nx = x + axis[i];
			int ny = y + axis[i + 1];
			if (nx < 0 || ny < 0 || nx >= grid.size() || ny >= grid[0].size() || grid[nx][ny] == 1)
				continue;
			if (cnt[nx][ny] > cnt[x][y] + 1) {
				cnt[nx][ny] = cnt[x][y] + 1;
				que.emplace(pair<int, int>(nx, ny));
			}
		}
	}
	return cnt[grid.size() - 1][grid[0].size() - 1] == INT_MAX ? -1 : cnt[grid.size() - 1][grid[0].size() - 1];
}
