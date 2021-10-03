#include <Solution.h>
#include <iostream>
#include <string>

using std::string;

vector<vector<int>> axis = {{1,0}, {0,1}, {0, -1}, {-1, 0}};

void PacificFlow(const vector<vector<int>>& heights, vector<vector<string>>& cnt, int x, int y) {
	if (x < 0 || y < 0 || x >= heights.size() || y >= heights[0].size() || cnt[x][y] == "a") return;
	cnt[x][y] += "a";
	for (const auto& ai : axis) {
		int i = x + ai[0];
		int j = y + ai[1];
		if (i < 0 || j < 0 || i >= heights.size() || j >= heights[0].size() || cnt[i][j] == "a" || heights[x][y] > heights[i][j]) continue;
		PacificFlow(heights, cnt, i, j);
	}
}

void AtlanticFlow(const vector<vector<int>>& heights, vector<vector<string>>& cnt, int x, int y) {
	if (x < 0 || y < 0 || x >= heights.size() || y >= heights[0].size() || cnt[x][y] == "b" || cnt[x][y] == "ab") return;
	cnt[x][y] += "b";
	for (const auto& ai : axis) {
		int i = x + ai[0];
		int j = y + ai[1];
		if (i < 0 || j < 0 || i >= heights.size() || j >= heights[0].size() || cnt[i][j] == "b" || cnt[i][j] == "ab" || heights[x][y] > heights[i][j]) continue;
		AtlanticFlow(heights, cnt, i, j);
	}
}

vector<vector<int>> Solution::pacificAtlantic(vector<vector<int>>& heights) {
	int m = heights.size();
	int n = heights[0].size();

	vector<vector<string>> cnt(m, vector<string>(n));
	vector<vector<int>> result;

	for (int i = 0 ; i < n ; ++i) PacificFlow(heights, cnt, 0, i);
	for (int j = 0 ; j < m ; ++j) PacificFlow(heights, cnt, j, 0);
	for (int i = 0 ; i < n ; ++i) AtlanticFlow(heights, cnt, m-1, i);
	for (int j = 0 ; j < m ; ++j) AtlanticFlow(heights, cnt, j, n-1);
	for (int i = 0 ; i < m ; ++i) {
		for (int j = 0 ; j < n ; ++j) {
			if (cnt[i][j] == "ab") {
				vector<int> tmp = {i, j};
				result.emplace_back(tmp);
			}
		}
	}
	return result;
}
