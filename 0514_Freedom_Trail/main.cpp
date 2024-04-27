#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string ring = "abcde";
	string key = "ade";
	Solution* test = new Solution();
	cout << test->findRotateSteps(ring, key) << endl;
	return 0;
}

