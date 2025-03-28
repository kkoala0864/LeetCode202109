#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> input = {{0, 1}, {1, 2}, {1, 3}, {4, 2}, {5, 3}, {6, 3}, {6, 7}, {8, 6}, {9, 0}, {5, 10}, {11, 9}, {12, 5}, {5, 13}, {8, 14}, {11, 15}, {8, 16}, {17, 0}, {18, 7}};
	Solution *test = new Solution();
	cout << test->minimumFuelCost(input, 13) << endl;
	return 0;
}
