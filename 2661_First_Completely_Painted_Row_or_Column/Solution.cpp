#include <Solution.h>
#include <iostream>

using std::pair;

int Solution::firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
	int m = mat.size();
	int n = mat[0].size();

	vector<pair<int, int>> coordinate(m * n + 1);

	for (int i = 0 ; i < m ; ++i) {
		for (int j = 0 ; j < n ; ++j) {
			coordinate[mat[i][j]] = pair<int,int>(i, j);
		}
	}

	vector<int> row(m, 0);
	vector<int> col(n, 0);
	for (int i = 0 ; i < arr.size() ; ++i) {
		int x = coordinate[arr[i]].first;
		int y = coordinate[arr[i]].second;
		++row[x];
		++col[y];
		if (row[x] == n || col[y] == m) return i;
	}
	return -1;
}
