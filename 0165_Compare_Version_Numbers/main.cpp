#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string s1 = "7.5.2.4";
	string s2 = "7.5.3";
	Solution* test = new Solution();
	cout << test->compareVersion(s1, s2) << endl;
	return 0;
}

