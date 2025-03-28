#include <Solution.h>
#include <iostream>

using std::pair;

vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

void getPattern(vector<vector<int>> &grid, int x, int y, int i, int j, vector<pair<int, int>> &pattern) {
	grid[x][y] = 0;
	pattern.push_back({x - i, y - j});
	for (const auto &d : dir) {
		int nx = x + d.first;
		int ny = y + d.second;
		if (nx < 0 || ny < 0 || nx >= grid.size() || ny >= grid[0].size() || grid[nx][ny] == 0)
			continue;
		getPattern(grid, nx, ny, i, j, pattern);
	}
}

int Solution::numDistinctIslands(vector<vector<int>> &grid) {
	vector<vector<pair<int, int>>> patterns;

	int m = grid.size();
	int n = grid[0].size();

	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			if (grid[i][j] == 0)
				continue;
			vector<pair<int, int>> tmp;
			getPattern(grid, i, j, i, j, tmp);
			bool find = false;
			for (const auto &pattern : patterns) {
				if (pattern.size() != tmp.size())
					continue;
				int i = 0;
				while (i < pattern.size()) {
					if (pattern[i].first == tmp[i].first && pattern[i].second == tmp[i].second)
						++i;
					else
						break;
					;
				}

				if (i == pattern.size()) {
					find = true;
					break;
				}
			}
			if (!find)
				patterns.emplace_back(tmp);
		}
	}
	return patterns.size();
}

void buildAndCompare(vector<vector<int>> &grid, int x, int y, int i, int j, Trie *&node) {
	grid[x][y] = 0;
	for (int di = 0; di < dir.size(); ++di) {
		int nx = x + dir[di].first;
		int ny = y + dir[di].second;
		if (nx < 0 || ny < 0 || nx >= grid.size() || ny >= grid[0].size() || grid[nx][ny] == 0)
			continue;
		if (!node->child[di]) {
			node->child[di] = new Trie();
		}
		node = node->child[di];
		buildAndCompare(grid, nx, ny, i, j, node);
	}

	if (!node->child[4])
		node->child[4] = new Trie();
	node = node->child[4];
}

int Solution::numDistinctIslandsTrie(vector<vector<int>> &grid) {
	Trie *head = new Trie();

	int m = grid.size();
	int n = grid[0].size();
	int result = 0;

	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			if (grid[i][j] == 0)
				continue;
			Trie *iter = head;
			buildAndCompare(grid, i, j, i, j, iter);
			if (!iter->End) {
				iter->End = true;
				++result;
			}
		}
	}
	return result;
}
