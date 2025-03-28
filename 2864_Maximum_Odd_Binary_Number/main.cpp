#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string input = "0101";
	Solution *test = new Solution();
	cout << test->maximumOddBinaryNumber(input) << endl;
	return 0;
}
