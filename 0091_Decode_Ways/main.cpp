#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {

	string input("0");
	Solution* test = new Solution();
	cout << test->numDecodings(input) << endl;
	cout << test->numDecodings2(input) << endl;
	return 0;
}

