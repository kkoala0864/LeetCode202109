#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	int n = 11;
	Solution* test = new Solution();
	cout << test->countDigitOne(n) << endl;
	return 0;
}

