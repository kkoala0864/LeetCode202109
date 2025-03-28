#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {7, 8, 9, 11, 12};
	Solution *test = new Solution();
	cout << test->firstMissingPositive(input) << endl;
	input = {7, 8, 9, 11, 12};
	cout << test->firstMissingPositive2(input) << endl;
	return 0;
}
