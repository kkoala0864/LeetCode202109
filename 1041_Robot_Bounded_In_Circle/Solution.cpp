#include <Solution.h>
#include <iostream>
#include <vector>

using std::vector;

bool Solution::isRobotBounded(string instructions) {
	vector<vector<int>> axis = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
	int x = 0;
	int y = 0;
	int i = 0;
	for (const auto &ch : instructions) {
		if (ch == 'L') {
			i = (i + 1) % 4;
		} else if (ch == 'R') {
			i = (i + 3) % 4;
		} else {
			x += axis[i][0];
			y += axis[i][1];
		}
	}
	return x == 0 && y == 0 || i != 0;
}
