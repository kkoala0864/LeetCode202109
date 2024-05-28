#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string s1 = "abcd";
	string s2 = "bcdf";
	Solution* test = new Solution();
	cout << test->equalSubstring(s1, s2, 3) << endl;
	return 0;
}

