#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string input = "abcdefd";
	char ch = 'd';
	Solution* test = new Solution();
	cout << test->reversePrefix(input, ch) << endl;
	return 0;
}

