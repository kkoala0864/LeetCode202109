#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> input = {{3, 3}, {2, 3}, {0, 0}, {2, 2}, {2, 1}, {3, 2}, {0, 2}};
	Solution *test = new Solution();
	cout << test->minAreaFreeRect(input) << endl;
	return 0;
}
