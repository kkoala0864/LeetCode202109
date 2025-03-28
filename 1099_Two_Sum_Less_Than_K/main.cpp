#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {34, 23, 1, 24, 75, 33, 54, 8};
	Solution *test = new Solution();
	cout << test->twoSumLessThanK(input, 60) << endl;
	return 0;
}
