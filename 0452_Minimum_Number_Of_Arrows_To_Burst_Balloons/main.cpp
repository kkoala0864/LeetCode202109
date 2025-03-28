#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> input = {{1, 2}, {2, 3}, {3, 4}, {4, 5}};
	Solution *test = new Solution();
	cout << test->findMinArrowShots(input) << endl;
	return 0;
}
