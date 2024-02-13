#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<string> input = {"abc","car","ada","racecar","cool"};
	Solution* test = new Solution();
	cout << test->firstPalindrome(input) << endl;
	return 0;
}

