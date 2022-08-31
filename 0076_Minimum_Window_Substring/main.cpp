#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string s("ADOBECODEBANC");
	string t("ABC");
	Solution* test = new Solution();
	cout << test->minWindow(s, t) << endl;
	cout << test->minWindow5(s, t) << endl;
	return 0;
}

