#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> input = {{2, 1, 3}, {6, 5, 4}, {7, 8, 9}};
	Solution *test = new Solution();
	cout << test->minFallingPathSum(input) << endl;
	return 0;
}
