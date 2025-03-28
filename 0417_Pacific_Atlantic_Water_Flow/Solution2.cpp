#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;
static vector<vector<int>> axis = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

void pTraverse(const vector<vector<int>> &heights, vector<vector<int>> &mark, int i, int j) {
	if (mark[i][j] != 0)
		return;

	mark[i][j] = 1;
	for (const auto &ai : axis) {
		int x = i + ai[0];
		int y = j + ai[1];
		if (x < 0 || x >= heights.size() || y < 0 || y >= heights[0].size() || heights[i][j] > heights[x][y] || mark[x][y] != 0)
			continue;
		pTraverse(heights, mark, x, y);
	}
}

void aTraverse(const vector<vector<int>> &heights, vector<vector<int>> &mark, int i, int j, vector<vector<int>> &result) {
	if (mark[i][j] > 1)
		return;

	mark[i][j] += 2;
	if (mark[i][j] == 3)
		result.push_back({i, j});

	for (const auto &ai : axis) {
		int x = i + ai[0];
		int y = j + ai[1];
		if (x < 0 || x >= heights.size() || y < 0 || y >= heights[0].size() || heights[i][j] > heights[x][y] || mark[x][y] > 1)
			continue;
		aTraverse(heights, mark, x, y, result);
	}
}

vector<vector<int>> Solution::pacificAtlantic2(vector<vector<int>> &heights) {
	vector<vector<int>> mark(heights.size(), vector<int>(heights[0].size(), 0));
	vector<vector<int>> result;

	for (int i = 0; i < heights.size(); ++i)
		pTraverse(heights, mark, i, 0);
	for (int j = 0; j < heights[0].size(); ++j)
		pTraverse(heights, mark, 0, j);

	for (int i = 0; i < heights.size(); ++i)
		aTraverse(heights, mark, i, heights[0].size() - 1, result);
	for (int j = 0; j < heights[0].size(); ++j)
		aTraverse(heights, mark, heights.size() - 1, j, result);
	return result;
}
