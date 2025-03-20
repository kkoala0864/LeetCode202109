#include <Solution.h>
#include <iostream>
#include <set>
#include <unordered_set>
#include <algorithm>
#include <string>

using std::unordered_set;
using std::cout;
using std::endl;
using std::string;
using std::to_string;
using std::pair;
using std::set;
using std::sort;

vector<int> dir = {1, 0, -1, 0, 1};

void dfs(vector<vector<int>>& grid, int x, int y, vector<pair<int, int>>& g) {
	g.emplace_back(pair<int, int>(x, y));
	grid[x][y] = 0;

	for (int i = 0 ; i < 4 ; ++i) {
		int nx = x + dir[i];
		int ny = y + dir[i+1];
		if (nx < 0 || ny < 0 || nx >= grid.size() || ny >= grid[0].size() || grid[nx][ny] == 0) continue;
		dfs(grid, nx, ny, g);
	}
}

string translate(const vector<pair<int, int>>& g) {
	vector<vector<pair<int, int>>> forms(8, vector<pair<int, int>>());

	set<string> formStr;
	for (const auto& v : g) {
		int x = v.first;
		int y = v.second;

		forms[0].emplace_back(pair<int, int>(x, y));
		forms[1].emplace_back(pair<int, int>(x, -y));
		forms[2].emplace_back(pair<int, int>(-x, y));
		forms[3].emplace_back(pair<int, int>(-x, -y));
		forms[4].emplace_back(pair<int, int>(y, x));
		forms[5].emplace_back(pair<int, int>(y, -x));
		forms[6].emplace_back(pair<int, int>(-y, x));
		forms[7].emplace_back(pair<int, int>(-y, -x));
	}

	for (int i = 0 ; i < 8 ; ++i) {
		sort(forms[i].begin(), forms[i].end());

		int minX = forms[i][0].first;
		int minY = forms[i][0].second;
		for (auto& v : forms[i]) {
			v.first -= minX;
			v.second -= minY;
		}

		string key;
		for (const auto& v : forms[i]) {
			key += to_string(v.first) + "_" + to_string(v.second) + "_";
		}
		formStr.emplace(key);
	}
	return *(formStr.begin());
}

int Solution::numDistinctIslands2(vector<vector<int>>& grid) {
	unordered_set<string> cnt;

	for (int i = 0 ; i < grid.size() ; ++i) {
		for (int j = 0 ; j < grid[0].size() ; ++j) {
			if (grid[i][j] == 0) continue;
			vector<pair<int, int>> g;
			dfs(grid, i, j, g);
			cnt.emplace(translate(g));
		}
	}
	return cnt.size();
}
