#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string input = "cccerrrecdcdccedecdcccddeeeddcdcddedccdceeedccecde";
	Solution *test = new Solution();
	cout << test->maximumLength(input) << endl;
	return 0;
}
