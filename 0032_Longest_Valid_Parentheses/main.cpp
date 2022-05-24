#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string input("())");
	Solution* test = new Solution();
	cout << test->longestValidParentheses3(input) << endl;
	cout << test->DP(input) << endl;
	return 0;
}

