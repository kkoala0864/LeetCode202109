#include <Solution.h>

int Solution::minimumArea(vector<vector<int>>& grid) {
	pair<int, int> mn(INT_MAX, INT_MAX), mx(INT_MIN, INT_MIN);

	for (int i = 0 ; i < grid.size() ; ++i) {
		for (int j = 0 ; j < grid[0].size() ; ++j) {
			if (grid[i][j] == 0) continue;
			mn.first = min(mn.first, i);
			mn.second = min(mn.second, j);
			mx.first = max(mx.first, i);
			mx.second = max(mx.second, j);
		}
	}
	if (mn.first == INT_MAX) return 0;
	return (mx.first - mn.first + 1) * (mx.second - mn.second + 1);
}
