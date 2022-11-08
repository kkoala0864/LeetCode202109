#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string num1("123");
	string num2("876");
	Solution* test = new Solution();
	cout << test->multiply(num1, num2) << endl;
	cout << test->multiply2(num1, num2) << endl;
	cout << test->multiply3(num1, num2) << endl;
	return 0;
}

