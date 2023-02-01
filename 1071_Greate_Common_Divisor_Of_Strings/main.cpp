#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string input1 = "ABABABC";
	string input2 = "ABAB";
	Solution* test = new Solution();
	cout << test->gcdOfStrings(input1, input2) << endl;
	return 0;
}

