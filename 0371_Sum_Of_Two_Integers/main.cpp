#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	int a = -1, b = 1;
	Solution* test = new Solution();
	cout << test->getSum(a, b) << endl;
	return 0;
}

