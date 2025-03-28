#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	Solution *test = new Solution();
	cout << test->isUgly(14) << endl;
	cout << test->isUgly2(14) << endl;
	return 0;
}
