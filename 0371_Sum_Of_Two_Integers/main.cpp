#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	int a = 3, b = 4;
	Solution* test = new Solution();
	cout << test->getSum(a, b) << endl;
	cout << test->getSum2(a, b) << endl;
	return 0;
}

