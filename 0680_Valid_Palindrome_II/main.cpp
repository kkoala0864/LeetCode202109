#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string input = "abc";
	Solution* test = new Solution();
	cout << test->validPalindrome(input) << endl;
	return 0;
}

