#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string input = "IIIDIDDD";
	Solution* test = new Solution();
	cout << test->smallestNumber(input) << endl;
	return 0;
}

