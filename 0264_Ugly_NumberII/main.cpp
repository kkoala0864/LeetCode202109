#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	Solution *test = new Solution();
	cout << test->nthUglyNumber(10) << endl;
	cout << test->nthUglyNumber2(10) << endl;
	return 0;
}
