#include <Solution.h>
#include <iostream>

void dfs(vector<vector<char>>& image, int x, int y, int& maxX, int& minX, int& maxY, int& minY) {
	image[x][y] = '0';

	maxX = max(maxX, x);
	minX = min(minX, x);
	maxY = max(maxY, y);
	minY = min(minY, y);

	vector<int> dir = {1, 0, -1, 0, 1};
	for (int i = 0 ; i < 4 ; ++i) {
		int nx = x + dir[i];
		int ny = y + dir[i+1];
		if (nx < 0 || ny < 0 || nx >= image.size() || ny >= image[0].size() || image[nx][ny] != '1') continue;
		dfs(image, nx, ny, maxX, minX, maxY, minY);
	}
}

int Solution::minArea(vector<vector<char>>& image, int x, int y) {
	int m = image.size();
	int n = image[0].size();
	int maxX = 0;
	int minX = m;
	int maxY = 0;
	int minY = n;

	dfs(image, x, y, maxX, minX, maxY, minY);
	return (maxX - minX + 1) * (maxY - minY + 1);
}
