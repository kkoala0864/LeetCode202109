#include <Solution.h>
#include <iostream>
using std::cout;
using std::endl;

vector<int> Solution::spiralOrder3(vector<vector<int>> &matrix) {
	int xs = 0, xe = matrix.size();
	int ys = 0, ye = matrix[0].size();
	int x = 0, y = 0;

	vector<int> result;
	while (result.size() < matrix.size() * matrix[0].size()) {
		while (ys < ye && xs < xe && y < ye)
			result.emplace_back(matrix[x][y++]);
		--y;
		++xs;
		++x;
		while (ys < ye && xs < xe && x < xe)
			result.emplace_back(matrix[x++][y]);
		--x;
		--ye;
		--y;
		while (ys < ye && xs < xe && y >= ys)
			result.emplace_back(matrix[x][y--]);
		++y;
		--xe;
		--x;
		while (ys < ye && xs < xe && x >= xs)
			result.emplace_back(matrix[x--][y]);
		++x;
		++ys;
		++y;
	}
	return result;
}
