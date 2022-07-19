#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string input = "PAYPALISHIRING";
	Solution* test = new Solution();
	cout << test->convert(input, 3) << endl;
	return 0;
}

