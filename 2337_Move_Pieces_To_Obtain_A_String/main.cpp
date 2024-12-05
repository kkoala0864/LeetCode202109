#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string s1 = "_L__R__R_";
	string s2 = "L______RR";
	Solution* test = new Solution();
	cout << test->canChange(s1, s2) << endl;
	return 0;
}

