#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string input = "Hello World";
	Solution* test = new Solution();
	cout << test->lengthOfLastWord(input) << endl;
	return 0;
}

