#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {

	string input("2611055971756562");
	Solution* test = new Solution();
	cout << test->numDecodings(input) << endl;
	return 0;
}

