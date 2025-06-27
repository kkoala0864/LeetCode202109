#include <Solution.h>

bool Solution::removeOnes(vector<vector<int>>& grid) {
	for (int i = 1 ; i < grid.size() ; ++i) {
		for (int j = 0 ; j < grid[0].size() ; ++j) {
			if ((grid[i][j] ^ grid[0][j]) != (grid[i][0] ^ grid[0][0])) return false;
		}
	}
	return true;
}
