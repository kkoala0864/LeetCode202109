#include <Solution.h>
#include <iostream>

using std::pair;

void Swap(vector<vector<int>> &matrix, const pair<int, int> &a, const pair<int, int> &b) {
	int tmp = matrix[a.first][a.second];
	matrix[a.first][a.second] = matrix[b.first][b.second];
	matrix[b.first][b.second] = tmp;
}

void Diagonal(vector<vector<int>> &matrix) {
	int n = matrix.size();
	vector<pair<int, int>> diagonalIdx;
	for (int i = 0; i < n; ++i) {
		diagonalIdx.emplace_back(pair<int, int>(i, n - 1 - i));
	}
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			Swap(matrix, pair<int, int>(diagonalIdx[i].first, diagonalIdx[j].second), pair<int, int>(diagonalIdx[j].first, diagonalIdx[i].second));
		}
	}
}

void Vertical(vector<vector<int>> &matrix) {
	int n = matrix.size();
	for (int i = 0; i < (n / 2); ++i) {
		matrix[i].swap(matrix[n - i - 1]);
	}
}

void Solution::rotate(vector<vector<int>> &matrix) {
	Diagonal(matrix);
	Vertical(matrix);
}
