#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string input = "aba";
	Solution* test = new Solution();
	cout << test->repeatedSubstringPattern(input) << endl;
	return 0;
}

