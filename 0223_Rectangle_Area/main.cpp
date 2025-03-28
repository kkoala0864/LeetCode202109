#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	Solution *test = new Solution();
	cout << test->computeArea(-2, -2, 2, 2, 3, 3, 4, 4) << endl;
	return 0;
}
