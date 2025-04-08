#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	int n = 65535;
	Solution *test = new Solution();
	cout << test->integerReplacement(n) << endl;
	return 0;
}
