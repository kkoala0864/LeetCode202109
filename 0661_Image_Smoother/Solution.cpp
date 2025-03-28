#include <Solution.h>
#include <iostream>

vector<vector<int>> Solution::imageSmoother(vector<vector<int>> &img) {
	auto result = img;
	int m = img.size();
	int n = img[0].size();
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			int cnt = 0;
			int sum = 0;
			for (int x = i - 1; x <= i + 1; ++x) {
				for (int y = j - 1; y <= j + 1; ++y) {
					if (x >= 0 && x < m && y >= 0 && y < n) {
						++cnt;
						sum += img[x][y];
					}
				}
			}
			result[i][j] = sum / cnt;
		}
	}
	return result;
}
