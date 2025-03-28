#include <Solution.h>
#include <iostream>

using std::swap;

vector<vector<char>> Solution::rotateTheBox(vector<vector<char>> &box) {
	int m = box.size();
	int n = box[0].size();

	vector<vector<char>> result(n, vector<char>(m, '.'));

	for (int i = 0; i < m; ++i) {
		int ei = n - 1;
		for (int j = n - 1; j >= 0; --j) {
			if (box[i][j] == '*') {
				ei = j - 1;
			} else if (box[i][j] == '#') {
				swap(box[i][j], box[i][ei--]);
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			result[i][j] = box[m - 1 - j][i];
		}
	}
	return result;
}
