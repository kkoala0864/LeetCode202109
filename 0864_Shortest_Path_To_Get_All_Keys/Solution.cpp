#include <Solution.h>
#include <iostream>
#include <queue>
#include <unordered_set>

using std::cout;
using std::endl;
using std::queue;
using std::unordered_set;

int Solution::shortestPathAllKeys(vector<string> &grid) {
	queue<vector<int>> que, next;
	vector<vector<unordered_set<int>>> visited(grid.size(), vector<unordered_set<int>>(grid[0].size(), unordered_set<int>()));

	int result = 0;
	int golden_key = 0;

	for (int i = 0; i < grid.size(); ++i) {
		for (int j = 0; j < grid[i].size(); ++j) {
			if (grid[i][j] == '@') {
				que.emplace(vector<int>({i, j, 0}));
				visited[i][j].emplace(0);
				grid[i][j] = '.';
			} else if (grid[i][j] >= 'a' && grid[i][j] <= 'z') {
				golden_key |= (1 << (grid[i][j] - 'a'));
			}
		}
	}

	vector<int> dir = {1, 0, -1, 0, 1};
	while (!que.empty()) {
		int x = que.front()[0];
		int y = que.front()[1];
		int keys = que.front()[2];
		que.pop();

		if (keys == golden_key)
			return result;

		for (int i = 0; i < 4; ++i) {
			int nx = x + dir[i];
			int ny = y + dir[i + 1];
			int curK = keys;
			if (nx < 0 || ny < 0 || nx >= grid.size() || ny >= grid[0].size() || grid[nx][ny] == '#')
				continue;
			if (visited[nx][ny].count(keys))
				continue;

			if (grid[nx][ny] >= 'a' && grid[nx][ny] <= 'z') {
				curK = keys | (1 << (grid[nx][ny] - 'a'));
			} else if (grid[nx][ny] >= 'A' && grid[nx][ny] <= 'Z') {
				if ((keys & (1 << (grid[nx][ny] - 'A'))) == 0)
					continue;
			}
			visited[nx][ny].emplace(curK);
			next.emplace(vector<int>({nx, ny, curK}));
		}
		if (que.empty()) {
			++result;
			que = move(next);
			cout << endl;
		}
	}
	return -1;
}
