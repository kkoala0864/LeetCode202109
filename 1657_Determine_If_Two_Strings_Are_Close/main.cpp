#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string input1 = "abc";
	string input2 = "bca";
	Solution *test = new Solution();
	cout << test->closeStrings(input1, input2) << endl;
	cout << test->closeStrings2(input1, input2) << endl;
	return 0;
}
