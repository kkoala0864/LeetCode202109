#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	Solution *test = new Solution();
	cout << test->isReachableAtTime(1, 2, 1, 2, 1) << endl;
	return 0;
}
