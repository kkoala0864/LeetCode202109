#include <Solution.h>
#include <iostream>
#include <map>

using std::map;
using std::pair;

int find(int val, int n, vector<vector<int>>& unionFind) {
	int x = val / n;
	int y = val % n;
	if (unionFind[x][y] == val) return val;
	return unionFind[x][y] = find(unionFind[x][y], n, unionFind);
}

int Solution::minimumEffortPath(vector<vector<int>>& heights) {
	int m = heights.size();
	int n = heights[0].size();
	map<int, vector<pair<int, int>>> diff;
	vector<vector<int>> unionFind(m, vector<int>(n, 0));

	for (int i = 0 ; i < m ; ++i) {
		for (int j = 0 ; j < n ; ++j) {
			if (j < n - 1) diff[abs(heights[i][j] - heights[i][j+1])].push_back({i*n+j, i*n+j+1});
			if (i < m - 1) diff[abs(heights[i][j] - heights[i+1][j])].push_back({i*n+j, (i+1)*n+j});
			unionFind[i][j] = i * n + j;
		}
	}

	int result = 0;
	for (const auto& iter : diff) {
		result = iter.first;
		for (const auto& edge : iter.second) {
			int first = find(edge.first, n, unionFind);
			int second = find(edge.second, n, unionFind);
			if (first < second) unionFind[second/n][second%n] = first;
			else unionFind[first/n][first%n] = second;
			if (find(m*n-1, n, unionFind) == 0) return result;
		}
	}
	return result;
}
