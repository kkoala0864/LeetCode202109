#include <Solution.h>

int getMin(map<int, int>& m) {
	if (m.size() == 1) return 0;
	auto iter = m.begin();
	auto next = std::next(iter);

	int result = INT_MAX;
	while (next != m.end()) {
		result = min(result, next->first - iter->first);
		++iter;
		++next;
	}
	return result;
}

vector<vector<int>> Solution::minAbsDiff(vector<vector<int>>& grid, int k) {
	int m = grid.size();
	int n = grid[0].size();
	vector<vector<int>> result(m - k + 1, vector<int>(n - k + 1, INT_MAX));

	map<int, int> valMap;
	for (int i = 0 ; i < k ; ++i) {
		for (int j = 0 ; j < k ; ++j) {
			++valMap[grid[i][j]];
		}
	}

	for (int i = 0 ; (i + k - 1) < m ; ++i) {
		if (i > 0) {
			for (int y = 0 ; y < k ; ++y) ++valMap[grid[i + k - 1][y]];
			for (int y = 0 ; y < k ; ++y) {
				--valMap[grid[i-1][y]];
				if (valMap[grid[i-1][y]] == 0) valMap.erase(grid[i-1][y]);
			}
		}
		auto colMap = valMap;
		for (int j = 0 ; (j + k - 1) < n ; ++j) {
			if (j > 0) {
				for (int x = 0 ; x < k ; ++x) ++colMap[grid[i + x][j + k - 1]];
				for (int x = 0 ; x < k ; ++x) {
					--colMap[grid[i+x][j-1]];
					if (colMap[grid[i+x][j-1]] == 0) colMap.erase(grid[i+x][j-1]);
				}
			}
			result[i][j] = getMin(colMap);
		}
	}
	return result;

}
