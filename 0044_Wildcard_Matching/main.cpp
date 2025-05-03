#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string s1 = "aa";
	string s2 = "*?*?*";
	Solution *test = new Solution();
	cout << test->isMatch(s1, s2) << endl;
	return 0;
}
