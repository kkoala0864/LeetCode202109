#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	Solution* test = new Solution();
	cout << test->fractionToDecimal(-50, 8) << endl;
	return 0;
}

