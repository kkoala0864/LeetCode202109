#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string input = "abcd";
	Solution* test = new Solution();
	cout << test->shortestPalindrome(input) << endl;
	return 0;
}

