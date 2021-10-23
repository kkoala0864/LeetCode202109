#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string pattern("abc");
	string s("b c a");
	Solution* test = new Solution();
	cout << test->wordPattern(pattern, s) << endl;
	return 0;
}

