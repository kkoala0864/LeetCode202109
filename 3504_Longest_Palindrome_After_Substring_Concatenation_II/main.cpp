#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string s1 = "ab";
	string s2 = "ba";
	Solution *test = new Solution();
	cout << test->longestPalindrome(s1, s2) << endl;
	return 0;
}
