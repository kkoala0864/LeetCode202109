#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<string> input = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
	Solution *test = new Solution();
	cout << test->evalRPN2(input) << endl;
	return 0;
}
