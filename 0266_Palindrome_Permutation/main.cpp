#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string input = "carerac";
	Solution *test = new Solution();
	cout << test->canPermutePalindrome(input) << endl;
	return 0;
}
