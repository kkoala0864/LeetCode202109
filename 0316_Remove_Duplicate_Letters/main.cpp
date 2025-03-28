#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string input("bcabc");
	Solution *test = new Solution();
	cout << test->removeDuplicateLetters(input) << endl;
	return 0;
}
