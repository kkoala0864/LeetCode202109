#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string input = "())(()(()(())()())(())((())(()())((())))))(((((((())(()))))(";
	string lock = "100011110110011011010111100111011101111110000101001101001111";
	Solution *test = new Solution();
	cout << test->canBeValid(input, lock) << endl;
	return 0;
}
