#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string input = "101";
	Solution* test = new Solution();
	cout << test->minimumSteps(input) << endl;
	return 0;
}

