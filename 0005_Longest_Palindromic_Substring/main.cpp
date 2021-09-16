#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string input = string("babad");
	Solution* test = new Solution();
	cout << test->longestPalindrome(input) << endl;
	return 0;
}

