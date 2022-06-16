#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string input = string("aaaa");
	Solution* test = new Solution();
	cout << test->longestPalindrome(input) << endl;
	cout << test->longestPalindrome2(input) << endl;
	cout << test->longestPalindrome3(input) << endl;
	cout << test->longestPalindrome4(input) << endl;
	return 0;
}

