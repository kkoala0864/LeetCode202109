#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string input = "34789";
	Solution* test = new Solution();
	cout << test->hasSameDigits(input) << endl;
	return 0;
}

