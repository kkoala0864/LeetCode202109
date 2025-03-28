#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> input = {{1, 2, 3}, {-1, -2, -3}, {1, 2, 3}};
	Solution *test = new Solution();
	cout << test->maxMatrixSum(input) << endl;
	return 0;
}
