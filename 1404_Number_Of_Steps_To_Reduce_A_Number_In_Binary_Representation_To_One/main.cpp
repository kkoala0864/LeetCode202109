#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string input = "10";
	Solution* test = new Solution();
	cout << test->numSteps(input) << endl;
	return 0;
}

