#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string input = "(1+(4+5+2)-3)+(6+8)";
	Solution *test = new Solution();
	cout << test->calculate(input) << endl;
	return 0;
}
