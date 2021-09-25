#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string input("race a car");
	Solution* test = new Solution();
	cout << test->isPalindrome(input) << endl;
	return 0;
}

