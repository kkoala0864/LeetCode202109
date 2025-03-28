#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string input = "35427";
	Solution *test = new Solution();
	cout << test->largestOddNumber(input) << endl;
	return 0;
}
