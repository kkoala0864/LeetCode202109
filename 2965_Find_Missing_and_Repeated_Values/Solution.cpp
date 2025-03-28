#include <Solution.h>
#include <iostream>

vector<int> Solution::findMissingAndRepeatedValues(vector<vector<int>> &grid) {
	int size = grid.size();
	vector<int> result(2, 0);
	vector<int> cnt(size * size + 1, 0);

	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			++cnt[grid[i][j]];
			if (cnt[grid[i][j]] == 2)
				result[0] = grid[i][j];
		}
	}
	for (int i = 1; i <= size * size; ++i) {
		if (cnt[i] != 0)
			continue;
		result[1] = i;
		break;
	}
	return result;
}
