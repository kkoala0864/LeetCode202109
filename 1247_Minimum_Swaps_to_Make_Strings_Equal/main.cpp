#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string s1 = "xx";
	string s2 = "yy";
	Solution* test = new Solution();
	cout << test->minimumSwap(s1, s2) << endl;
	return 0;
}

