#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string input = "GL";
	Solution* test = new Solution();
	cout << test->isRobotBounded(input) << endl;
	return 0;
}

