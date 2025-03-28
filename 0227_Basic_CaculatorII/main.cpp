#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string input = "3+2*2";
	Solution *test = new Solution();
	cout << test->calculate(input) << endl;
	return 0;
}
