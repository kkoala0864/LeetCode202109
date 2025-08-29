#include <Solution.h>

vector<vector<int>> Solution::sortMatrix(vector<vector<int>> &grid) {
	unordered_map<int, vector<int>> m;
	int n = grid.size();
	for (int i = 0 ; i < n ; ++i) {
		for (int j = 0 ; j < n ; ++j) {
			int offset = j - i;
			m[offset].emplace_back(grid[i][j]);
		}
	}

	for (auto& e : m) {
		if (e.first <= 0) {
			sort(e.second.begin(), e.second.end());
		} else {
			sort(e.second.rbegin(), e.second.rend());
		}
	}

	for (int i = 0 ; i < n ; ++i) {
		for (int j = 0 ; j < n ; ++j) {
			int offset = j - i;
			grid[i][j] = m[offset].back();
			m[offset].pop_back();
		}
	}
	return grid;
}
