#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string s = "z";
	Solution *test = new Solution();
	cout << test->smallestPalindrome(s) << endl;
	return 0;
}
