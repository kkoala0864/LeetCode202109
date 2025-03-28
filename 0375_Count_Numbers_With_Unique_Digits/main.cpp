#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	Solution *test = new Solution();
	cout << test->countNumbersWithUniqueDigits(3) << endl;
	return 0;
}
