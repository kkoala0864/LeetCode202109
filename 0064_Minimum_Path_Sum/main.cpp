#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> input = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
	Solution *test = new Solution();
	cout << test->minPathSum(input) << endl;
	return 0;
}
