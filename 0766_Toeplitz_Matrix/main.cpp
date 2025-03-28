#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> input = {{1, 2, 3, 4}, {5, 1, 2, 3}, {9, 5, 1, 2}};
	Solution *test = new Solution();
	cout << test->isToeplitzMatrix(input) << endl;
	return 0;
}
