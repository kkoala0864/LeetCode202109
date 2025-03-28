#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<string> input = {"5", "-2", "4", "C", "D", "9", "+", "+"};
	Solution *test = new Solution();
	cout << test->calPoints(input) << endl;
	return 0;
}
