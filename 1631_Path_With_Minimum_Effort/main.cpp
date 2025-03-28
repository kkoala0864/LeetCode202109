#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> input = {{1, 2, 2}, {3, 8, 2}, {5, 3, 5}};
	Solution *test = new Solution();
	cout << test->minimumEffortPath(input) << endl;
	return 0;
}
