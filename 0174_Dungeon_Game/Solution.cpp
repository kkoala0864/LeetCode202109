#include <Solution.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using std::vector;
using std::max;
using std::min;


int getMinHealth(const vector<vector<int>>& dp, int curCell, int x, int y, int xSize, int ySize) {
	if (x >= xSize || y >= ySize) return INT_MAX;

	int nextCell = dp[x][y];
	return max(1, nextCell - curCell);
}

int Solution::calculateMinimumHP(vector<vector<int>>& dungeon) {
	int xSize = dungeon.size();
	int ySize = dungeon[0].size();
	vector<vector<int>> dp(xSize, vector<int>(ySize, INT_MAX));

	int curCell, rH, dH, nextH, minH;
	for (int x = xSize - 1 ; x >= 0 ; --x) {
		for (int y = ySize - 1 ; y >= 0 ; --y) {
			curCell = dungeon[x][y];
			rH = getMinHealth(dp, curCell, x, y+1, xSize, ySize);
			dH = getMinHealth(dp, curCell, x+1, y, xSize, ySize);
			nextH = min(rH, dH);

			if (nextH != INT_MAX) {
				minH = nextH;
			} else {
				minH = curCell >= 0 ? 1 : 1 - curCell;
			}
			dp[x][y] = minH;
		}
	}
	return dp[0][0];
}
