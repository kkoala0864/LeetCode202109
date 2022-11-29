#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string input = "bacddcxyab";
	Solution* test = new Solution();
	cout << test->isValidPalindrome(input, 2) << endl;
	return 0;
}

