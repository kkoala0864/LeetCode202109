#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string input = "1212";
	Solution *test = new Solution();
	cout << test->equalDigitFrequency(input) << endl;
	return 0;
}
