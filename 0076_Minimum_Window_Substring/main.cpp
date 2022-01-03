#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string s("ADOBECODEBANC");
	string t("ABC");
	Solution* test = new Solution();
	cout << test->minWindow(s, t) << endl;
	cout << test->minWindow3(s, t) << endl;
	cout << test->minWindow4(s, t) << endl;
	return 0;
}

