#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string pattern("abba");
	string s("dogcatcatdog");
	Solution* test = new Solution();
	cout << test->wordPatternMatch(pattern, s) << endl;
	return 0;
}

