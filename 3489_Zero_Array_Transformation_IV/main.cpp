#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> nums = {1, 2, 3, 2, 6};
	vector<vector<int>> queries = {{0, 1, 1}, {0, 2, 1}, {1, 4, 2}, {4, 4, 4}, {3, 4, 1}, {4, 4, 5}};
	Solution *test = new Solution();
	cout << test->minZeroArray(nums, queries) << endl;
	return 0;
}
