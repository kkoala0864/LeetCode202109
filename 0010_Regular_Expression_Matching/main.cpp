#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string input = "aabcbcbcaccbcaabc";
	string pattern = ".*a*aa*.*b*.c*.*a*";
	Solution* test = new Solution();
	cout << test->isMatch(input, pattern) << endl;
	return 0;
}

