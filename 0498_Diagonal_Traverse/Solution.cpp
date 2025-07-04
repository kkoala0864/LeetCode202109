#include <Solution.h>

vector<int> Solution::findDiagonalOrder(vector<vector<int>>& mat) {
	int m = mat.size();
	int n = mat[0].size();
	int listCnt = 0;
	vector<int> result;

	for (int i = 0 ; i < n ; ++i) {
		int x = 0, y = i;
		int cnt = 0;
		while (x >= 0 && x < m && y >= 0 && y < n) {
			++cnt;
			result.emplace_back(mat[x][y]);
			++x;
			--y;
		}
		if ((listCnt & 1) == 0) {
			reverse(result.end() - cnt, result.end());
		}
		++listCnt;
	}
	for (int i = 1 ; i < m ; ++i) {
		int x = i, y = n-1;
		int cnt = 0;

		while (x >= 0 && x < m && y >= 0 && y < n) {
			++cnt;
			result.emplace_back(mat[x][y]);
			++x;
			--y;
		}
		if ((listCnt & 1) == 0) {
			reverse(result.end() - cnt, result.end());
		}
		++listCnt;
	}
	return result;
}
