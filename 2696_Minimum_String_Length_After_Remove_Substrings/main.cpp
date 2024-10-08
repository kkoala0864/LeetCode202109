#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string input = "ABFCACDB";
	Solution* test = new Solution();
	cout << test->minLength(input) << endl;
	return 0;
}

