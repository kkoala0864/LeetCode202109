#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	int num1 = 1, num2 = 12;
	Solution* test = new Solution();
	cout << test->minimizeXor(num1, num2) << endl;
	return 0;
}

