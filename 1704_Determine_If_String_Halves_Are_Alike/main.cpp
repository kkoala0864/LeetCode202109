#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string input = "textbook";
	Solution* test = new Solution();
	cout << test->halvesAreAlike(input) << endl;
	return 0;
}

