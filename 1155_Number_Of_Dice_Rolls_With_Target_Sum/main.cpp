#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	Solution* test = new Solution();
	cout << test->numRollsToTarget(30, 30, 500) << endl;
	return 0;
}

