#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string input1 = "ABABAB";
	string input2 = "ABAB";
	Solution* test = new Solution();
	cout << test->gcdOfStrings(input1, input2) << endl;
	cout << test->gcdOfStrings2(input1, input2) << endl;
	return 0;
}

