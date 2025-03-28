#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> input = {{3, 2, 10}, {1, 4, 2}, {4, 1, 3}};
	Solution *test = new Solution();
	cout << test->sellingWood(4, 6, input) << endl;
	return 0;
}
