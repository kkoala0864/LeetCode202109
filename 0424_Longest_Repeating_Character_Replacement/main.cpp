#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string input("ABBBA");
	Solution* test = new Solution();
	cout << test->characterReplacement(input, 2) << endl;
	cout << test->characterReplacement2(input, 2) << endl;
	cout << test->characterReplacement3(input, 2) << endl;
	return 0;
}

