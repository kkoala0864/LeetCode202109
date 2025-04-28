#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> input = {{1,2},{2,1},{3,3},{2,2},{1,1},{1,3},{2,3},{3,2},{3,1}};
	int row = 3;
	int col = 3;
	Solution *test = new Solution();
	cout << test->latestDayToCross(row, col, input) << endl;
	return 0;
}
