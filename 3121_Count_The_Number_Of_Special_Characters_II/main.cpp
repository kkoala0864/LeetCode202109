#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string input = "aaAbcBC";
	Solution* test = new Solution();
	cout << test->numberOfSpecialChars(input) << endl;
	return 0;
}

