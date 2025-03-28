#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string input = "(ed(et(oc))el)";
	Solution *test = new Solution();
	cout << test->reverseParentheses(input) << endl;
	return 0;
}
