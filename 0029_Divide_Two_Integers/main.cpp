#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	Solution *test = new Solution();
	int dividend = 10;
	int divisor = 3;
	cout << test->divide(dividend, divisor) << endl;
	cout << test->addingPowerOfTwo(dividend, divisor) << endl;
	return 0;
}
