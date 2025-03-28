#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string input = "abccba";
	Solution *test = new Solution();
	cout << test->breakPalindrome(input) << endl;
	return 0;
}
