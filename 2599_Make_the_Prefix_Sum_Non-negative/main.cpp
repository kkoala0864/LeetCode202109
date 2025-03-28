#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {6, -6, -3, 3, 1, 5, -4, -3, -2, -3, 4, -1, 4, 4, -2, 6, 0};
	Solution *test = new Solution();
	cout << test->makePrefSumNonNegative(input) << endl;
	return 0;
}
