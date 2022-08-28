#include <Solution.h>
#include <iostream>
#include <unordered_map>

using std::unordered_map;

vector<vector<int>> Solution::diagonalSort(vector<vector<int>>& mat) {
	vector<vector<int>> valCordinate(101, vector<int>());

	for (int i = 0 ; i < mat.size() ; ++i) {
		for (int j = 0 ; j < mat[0].size() ; ++j) {
			valCordinate[mat[i][j]].emplace_back(j - i);
		}
	}

	unordered_map<int, int> idx;
	for (int i = 1 ; i <= 100 ; ++i) {
		for (const auto& v : valCordinate[i]) {
			int x = v > 0 ? 0 : 0 - v;
			int y = v > 0 ? v : 0;
			x += idx[v];
			y += idx[v];
			++idx[v];

			mat[x][y] = i;
		}
	}
	return mat;
}
