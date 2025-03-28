#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> input = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
	Solution *test = new Solution();
	cout << test->minimumTotal(input) << endl;
	cout << test->minimumTotal2(input) << endl;
	cout << test->minimumTotal3(input) << endl;
	return 0;
}
