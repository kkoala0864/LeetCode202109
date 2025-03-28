#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> input = {{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}};
	Solution *test = new Solution();
	cout << test->mostPoints(input) << endl;
	return 0;
}
