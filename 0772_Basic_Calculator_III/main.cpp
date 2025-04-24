#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string input = "1*2-3/4+5*6-7*8+9/10";
	Solution *test = new Solution();
	cout << test->calculate(input) << endl;
	return 0;
}
