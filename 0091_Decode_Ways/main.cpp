#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {

	string input("226");
	Solution* test = new Solution();
	cout << test->numDecodings(input) << endl;
	cout << test->numDecodings2(input) << endl;
	cout << test->numDecodings3(input) << endl;
	return 0;
}

