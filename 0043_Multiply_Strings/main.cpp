#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string num1("12345678");
	string num2("87654321");
	Solution* test = new Solution();
	cout << test->multiply(num1, num2) << endl;
	return 0;
}

