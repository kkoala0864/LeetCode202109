#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string s1 = "bank";
	string s2 = "kanb";
	Solution* test = new Solution();
	cout << test->areAlmostEqual(s1, s2) << endl;
	return 0;
}

