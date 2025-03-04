#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	int n = 21;
	Solution* test = new Solution();
	cout << test->checkPowersOfThree(n) << endl;
	return 0;
}

