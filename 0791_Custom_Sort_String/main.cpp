#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string input1 = "cba";
	string input2 = "abcd";
	Solution *test = new Solution();
	cout << test->customSortString(input1, input2) << endl;
	return 0;
}
