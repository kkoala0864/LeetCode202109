#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {1, 2, 3, 4};
	Solution *test = new Solution();
	cout << test->rangeSum(input, 4, 1, 5) << endl;
	return 0;
}
