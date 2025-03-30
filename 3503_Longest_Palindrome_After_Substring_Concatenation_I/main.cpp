#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string s1 = "hc";
	string s2 = "jooh";

	Solution *test = new Solution();
	cout << test->longestPalindrome(s1, s2) << endl;
	return 0;
}
